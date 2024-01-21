;; Auto-generated. Do not edit!


(when (boundp 'tutorials::multiplier)
  (if (not (find-package "TUTORIALS"))
    (make-package "TUTORIALS"))
  (shadow 'multiplier (find-package "TUTORIALS")))
(unless (find-package "TUTORIALS::MULTIPLIER")
  (make-package "TUTORIALS::MULTIPLIER"))
(unless (find-package "TUTORIALS::MULTIPLIERREQUEST")
  (make-package "TUTORIALS::MULTIPLIERREQUEST"))
(unless (find-package "TUTORIALS::MULTIPLIERRESPONSE")
  (make-package "TUTORIALS::MULTIPLIERRESPONSE"))

(in-package "ROS")





(defclass tutorials::multiplierRequest
  :super ros::object
  :slots (_a _b ))

(defmethod tutorials::multiplierRequest
  (:init
   (&key
    ((:a __a) 0)
    ((:b __b) 0)
    )
   (send-super :init)
   (setq _a (round __a))
   (setq _b (round __b))
   self)
  (:a
   (&optional __a)
   (if __a (setq _a __a)) _a)
  (:b
   (&optional __b)
   (if __b (setq _b __b)) _b)
  (:serialization-length
   ()
   (+
    ;; int32 _a
    4
    ;; int32 _b
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _a
       (write-long _a s)
     ;; int32 _b
       (write-long _b s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _a
     (setq _a (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _b
     (setq _b (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass tutorials::multiplierResponse
  :super ros::object
  :slots (_result ))

(defmethod tutorials::multiplierResponse
  (:init
   (&key
    ((:result __result) 0)
    )
   (send-super :init)
   (setq _result (round __result))
   self)
  (:result
   (&optional __result)
   (if __result (setq _result __result)) _result)
  (:serialization-length
   ()
   (+
    ;; int32 _result
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _result
       (write-long _result s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _result
     (setq _result (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass tutorials::multiplier
  :super ros::object
  :slots ())

(setf (get tutorials::multiplier :md5sum-) "a7d7d7065d45755acef7d4dcf908162a")
(setf (get tutorials::multiplier :datatype-) "tutorials/multiplier")
(setf (get tutorials::multiplier :request) tutorials::multiplierRequest)
(setf (get tutorials::multiplier :response) tutorials::multiplierResponse)

(defmethod tutorials::multiplierRequest
  (:response () (instance tutorials::multiplierResponse :init)))

(setf (get tutorials::multiplierRequest :md5sum-) "a7d7d7065d45755acef7d4dcf908162a")
(setf (get tutorials::multiplierRequest :datatype-) "tutorials/multiplierRequest")
(setf (get tutorials::multiplierRequest :definition-)
      "int32 a
int32 b
---
int32 result
")

(setf (get tutorials::multiplierResponse :md5sum-) "a7d7d7065d45755acef7d4dcf908162a")
(setf (get tutorials::multiplierResponse :datatype-) "tutorials/multiplierResponse")
(setf (get tutorials::multiplierResponse :definition-)
      "int32 a
int32 b
---
int32 result
")



(provide :tutorials/multiplier "a7d7d7065d45755acef7d4dcf908162a")


