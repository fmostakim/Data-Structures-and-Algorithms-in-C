import cv2
import math
from ultralytics import YOLO

def main():
    # 1. Load the YOLOv8 model
    # 'yolov8n.pt' is the nano version - fastest for real-time on CPU.
    # It will automatically download the weight file if not present.
    print("Loading YOLOv8 model...")
    model = YOLO('yolov8n.pt')

    # 2. Initialize the webcam
    # 0 is usually the default ID for built-in webcams. 
    # Try 1 if you have an external camera connected.
    cap = cv2.VideoCapture(0)

    # Check if camera opened successfully
    if not cap.isOpened():
        print("Error: Could not open webcam.")
        return

    # Set camera resolution (optional, but good for performance control)
    cap.set(3, 640) # Width
    cap.set(4, 480) # Height

    print("Starting webcam feed. Press 'q' to quit.")

    # 3. Define the classes that YOLOv8n is trained on (COCO dataset)
    # This helps us map class IDs (integers) to readable names.
    classNames = ["person", "bicycle", "car", "motorbike", "aeroplane", "bus", "train", "truck", "boat",
                  "traffic light", "fire hydrant", "stop sign", "parking meter", "bench", "bird", "cat",
                  "dog", "horse", "sheep", "cow", "elephant", "bear", "zebra", "giraffe", "backpack", "umbrella",
                  "handbag", "tie", "suitcase", "frisbee", "skis", "snowboard", "sports ball", "kite", "baseball bat",
                  "baseball glove", "skateboard", "surfboard", "tennis racket", "bottle", "wine glass", "cup",
                  "fork", "knife", "spoon", "bowl", "banana", "apple", "sandwich", "orange", "broccoli",
                  "carrot", "hot dog", "pizza", "donut", "cake", "chair", "sofa", "pottedplant", "bed",
                  "diningtable", "toilet", "tvmonitor", "laptop", "mouse", "remote", "keyboard", "cell phone",
                  "microwave", "oven", "toaster", "sink", "refrigerator", "book", "clock", "vase", "scissors",
                  "teddy bear", "hair drier", "toothbrush"
                  ]

    while True:
        # Read a frame from the webcam
        success, img = cap.read()
        
        if not success:
            print("Failed to read frame.")
            break

        # 4. Run object detection on the frame
        # stream=True is efficient for processing video generators
        results = model(img, stream=True, verbose=False)

        # 5. Process the results
        for r in results:
            boxes = r.boxes

            for box in boxes:
                # --- Bounding Box ---
                # Get box coordinates (x1, y1, x2, y2)
                # content is tensor, so we convert to int
                x1, y1, x2, y2 = box.xyxy[0]
                x1, y1, x2, y2 = int(x1), int(y1), int(x2), int(y2)

                # Draw the bounding box
                # Color is BGR (Blue, Green, Red). (255, 0, 255) is Magenta.
                cv2.rectangle(img, (x1, y1), (x2, y2), (255, 0, 255), 3)

                # --- Confidence Score ---
                conf = math.ceil((box.conf[0] * 100)) / 100
                
                # --- Class Name ---
                cls = int(box.cls[0])
                currentClass = classNames[cls]

                # Create the label text (e.g., "Person 90%")
                label = f'{currentClass} {int(conf*100)}%'

                # --- Label Styling ---
                # Calculate text size to create a background box for the text
                (w, h), _ = cv2.getTextSize(label, cv2.FONT_HERSHEY_SIMPLEX, 0.5, 1)
                
                # Draw filled rectangle behind text for better visibility
                cv2.rectangle(img, (x1, y1 - 20), (x1 + w, y1), (255, 0, 255), -1)
                
                # Draw text on top of the filled rectangle
                cv2.putText(img, label, (x1, y1 - 5), cv2.FONT_HERSHEY_SIMPLEX, 
                            0.5, (255, 255, 255), 1)

        # 6. Display the frame
        cv2.imshow('YOLOv8 Real-Time Detection', img)

        # 7. Quit logic
        # Wait 1ms for a key press. If 'q' is pressed, break loop.
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    # Cleanup
    cap.release()
    cv2.destroyAllWindows()
    print("Program ended.")

if __name__ == "__main__":
    main()