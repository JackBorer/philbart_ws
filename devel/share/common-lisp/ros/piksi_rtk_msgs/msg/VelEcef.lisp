; Auto-generated. Do not edit!


(cl:in-package piksi_rtk_msgs-msg)


;//! \htmlinclude VelEcef.msg.html

(cl:defclass <VelEcef> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (tow
    :reader tow
    :initarg :tow
    :type cl:integer
    :initform 0)
   (x
    :reader x
    :initarg :x
    :type cl:integer
    :initform 0)
   (y
    :reader y
    :initarg :y
    :type cl:integer
    :initform 0)
   (z
    :reader z
    :initarg :z
    :type cl:integer
    :initform 0)
   (accuracy
    :reader accuracy
    :initarg :accuracy
    :type cl:fixnum
    :initform 0)
   (n_sats
    :reader n_sats
    :initarg :n_sats
    :type cl:fixnum
    :initform 0)
   (flags
    :reader flags
    :initarg :flags
    :type cl:fixnum
    :initform 0))
)

(cl:defclass VelEcef (<VelEcef>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <VelEcef>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'VelEcef)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name piksi_rtk_msgs-msg:<VelEcef> is deprecated: use piksi_rtk_msgs-msg:VelEcef instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <VelEcef>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:header-val is deprecated.  Use piksi_rtk_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'tow-val :lambda-list '(m))
(cl:defmethod tow-val ((m <VelEcef>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:tow-val is deprecated.  Use piksi_rtk_msgs-msg:tow instead.")
  (tow m))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <VelEcef>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:x-val is deprecated.  Use piksi_rtk_msgs-msg:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <VelEcef>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:y-val is deprecated.  Use piksi_rtk_msgs-msg:y instead.")
  (y m))

(cl:ensure-generic-function 'z-val :lambda-list '(m))
(cl:defmethod z-val ((m <VelEcef>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:z-val is deprecated.  Use piksi_rtk_msgs-msg:z instead.")
  (z m))

(cl:ensure-generic-function 'accuracy-val :lambda-list '(m))
(cl:defmethod accuracy-val ((m <VelEcef>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:accuracy-val is deprecated.  Use piksi_rtk_msgs-msg:accuracy instead.")
  (accuracy m))

(cl:ensure-generic-function 'n_sats-val :lambda-list '(m))
(cl:defmethod n_sats-val ((m <VelEcef>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:n_sats-val is deprecated.  Use piksi_rtk_msgs-msg:n_sats instead.")
  (n_sats m))

(cl:ensure-generic-function 'flags-val :lambda-list '(m))
(cl:defmethod flags-val ((m <VelEcef>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piksi_rtk_msgs-msg:flags-val is deprecated.  Use piksi_rtk_msgs-msg:flags instead.")
  (flags m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <VelEcef>) ostream)
  "Serializes a message object of type '<VelEcef>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'tow)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'tow)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'x)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'y)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'z)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'accuracy)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'accuracy)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'n_sats)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'flags)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <VelEcef>) istream)
  "Deserializes a message object of type '<VelEcef>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'tow)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'x) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'y) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'z) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'accuracy)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'accuracy)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'n_sats)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'flags)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<VelEcef>)))
  "Returns string type for a message object of type '<VelEcef>"
  "piksi_rtk_msgs/VelEcef")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'VelEcef)))
  "Returns string type for a message object of type 'VelEcef"
  "piksi_rtk_msgs/VelEcef")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<VelEcef>)))
  "Returns md5sum for a message object of type '<VelEcef>"
  "b632ba03d94241cc519a3a3e4885b973")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'VelEcef)))
  "Returns md5sum for a message object of type 'VelEcef"
  "b632ba03d94241cc519a3a3e4885b973")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<VelEcef>)))
  "Returns full string definition for message of type '<VelEcef>"
  (cl:format cl:nil "# This message reports the velocity in Earth Centered Earth Fixed (ECEF) coordinates. The full GPS time~%# is given by the preceding MSG GPS TIME with the matching time-of-week (tow).~%~%Header header~%~%uint32 tow      # GPS Time of Week.~%int32 x         # Velocity ECEF X coordinate [mm/s].~%int32 y         # Velocity ECEF Y coordinate [mm/s].~%int32 z         # Velocity ECEF Z coordinate [mm/s].~%uint16 accuracy # Velocity accuracy estimate (not implemented). Defaults to 0.~%uint8 n_sats    # Number of satellites used in solution.~%uint8 flags     # Status flags (reserved), see MSG_VEL_ECEF message description in SBP documentation.~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'VelEcef)))
  "Returns full string definition for message of type 'VelEcef"
  (cl:format cl:nil "# This message reports the velocity in Earth Centered Earth Fixed (ECEF) coordinates. The full GPS time~%# is given by the preceding MSG GPS TIME with the matching time-of-week (tow).~%~%Header header~%~%uint32 tow      # GPS Time of Week.~%int32 x         # Velocity ECEF X coordinate [mm/s].~%int32 y         # Velocity ECEF Y coordinate [mm/s].~%int32 z         # Velocity ECEF Z coordinate [mm/s].~%uint16 accuracy # Velocity accuracy estimate (not implemented). Defaults to 0.~%uint8 n_sats    # Number of satellites used in solution.~%uint8 flags     # Status flags (reserved), see MSG_VEL_ECEF message description in SBP documentation.~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <VelEcef>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4
     4
     4
     2
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <VelEcef>))
  "Converts a ROS message object to a list"
  (cl:list 'VelEcef
    (cl:cons ':header (header msg))
    (cl:cons ':tow (tow msg))
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
    (cl:cons ':z (z msg))
    (cl:cons ':accuracy (accuracy msg))
    (cl:cons ':n_sats (n_sats msg))
    (cl:cons ':flags (flags msg))
))
