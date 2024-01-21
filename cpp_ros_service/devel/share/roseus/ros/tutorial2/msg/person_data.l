;; Auto-generated. Do not edit!


(when (boundp 'tutorial2::person_data)
  (if (not (find-package "TUTORIAL2"))
    (make-package "TUTORIAL2"))
  (shadow 'person_data (find-package "TUTORIAL2")))
(unless (find-package "TUTORIAL2::PERSON_DATA")
  (make-package "TUTORIAL2::PERSON_DATA"))

(in-package "ROS")
;;//! \htmlinclude person_data.msg.html


(defclass tutorial2::person_data
  :super ros::object
  :slots (_name _age _color ))

(defmethod tutorial2::person_data
  (:init
   (&key
    ((:name __name) "")
    ((:age __age) 0)
    ((:color __color) "")
    )
   (send-super :init)
   (setq _name (string __name))
   (setq _age (round __age))
   (setq _color (string __color))
   self)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:age
   (&optional __age)
   (if __age (setq _age __age)) _age)
  (:color
   (&optional __color)
   (if __color (setq _color __color)) _color)
  (:serialization-length
   ()
   (+
    ;; string _name
    4 (length _name)
    ;; uint8 _age
    1
    ;; string _color
    4 (length _color)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; uint8 _age
       (write-byte _age s)
     ;; string _color
       (write-long (length _color) s) (princ _color s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint8 _age
     (setq _age (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; string _color
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _color (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get tutorial2::person_data :md5sum-) "fcc4ac2f30ce95ce4aadb3be7c765c64")
(setf (get tutorial2::person_data :datatype-) "tutorial2/person_data")
(setf (get tutorial2::person_data :definition-)
      "string name
uint8 age
string color
")



(provide :tutorial2/person_data "fcc4ac2f30ce95ce4aadb3be7c765c64")


