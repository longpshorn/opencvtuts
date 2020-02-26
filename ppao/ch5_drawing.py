#!/Users/patrick/.virtualenvs/cv/bin/python3

import numpy as np
import cv2

# Create canvas
canvas = np.zeros((300, 300, 3), dtype="uint8")

# draw rectangles
for i in np.arange(0, 30):
    for j in np.arange(0, 30):
        startX = 10 * i
        startY = 10 * j
        endX = 10 * (i + 1)
        endY = 10 * (j + 1)
        color = (0, 0, 255) if (i + j) % 2 == 0 else (0, 0, 0)
        cv2.rectangle(canvas, (startX, startY), (endX, endY), color, -1)

(centerX, centerY) = (canvas.shape[1] // 2, canvas.shape[0] // 2)
cv2.circle(canvas, (centerX, centerY), 50, (0, 255, 0), -1)
cv2.imshow("Canvas", canvas)
cv2.waitKey(0)
