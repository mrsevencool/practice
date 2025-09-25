import cv2
import numpy as np

image = cv2.imread("test3.jpg")  # читаем картинку
cv2.imshow("original", image)    # показываем оригинал
cv2.waitKey(0)

blurred_image = cv2.GaussianBlur(image, (11, 11), 0)  # размытие для снижения шума
cv2.imshow("blurred", blurred_image)
cv2.waitKey(0)

hsv_image = cv2.cvtColor(blurred_image, cv2.COLOR_BGR2HSV)  # переводим в hsv
cv2.imshow("HSV", hsv_image)
cv2.waitKey(0)

lower_bound = np.array([0, 30, 30])   # нижняя граница цвета
upper_bound = np.array([179, 255, 255])  # верхняя граница цвета

mask = cv2.inRange(hsv_image, lower_bound, upper_bound)  # маска нужного цвета
cv2.imshow("Mask", mask)
cv2.waitKey(0)

contours, hierarchy = cv2.findContours(mask.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)  # ищем контуры

sorted_contours = sorted(contours, key=cv2.contourArea, reverse=True)  # сортируем по площади
largest_contour = sorted_contours[0]  # берём самый большой

x, y, w, h = cv2.boundingRect(largest_contour)  # прямоугольник вокруг объекта
print(x, y, w, h)

cx = int(x + w/2)  # центр по x
cy = int(y + h/2)  # центр по y
print(cx, cy)

cv2.circle(image, (cx, cy), 7, (0, 0, 255), -1)  # рисуем красную точку в центре

cv2.drawContours(image, [largest_contour], -1, (0, 0, 255), 2)  # обводим объект красной рамкой

cv2.imshow("result", image)
cv2.waitKey(0)
cv2.destroyAllWindows()