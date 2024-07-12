int maxArea(int *height, int heightSize) {
  int maxArea = 0;
  int left = 0;
  int right = heightSize - 1;

  while (left < right) {
    int minHeight = height[left] < height[right] ? height[left] : height[right];
    int currentArea = (right - left) * minHeight;
    maxArea = currentArea > maxArea ? currentArea : maxArea;

    if (height[left] < height[right]) {
      left++;
    } else {
      right--;
    }
  }

  return maxArea;
}