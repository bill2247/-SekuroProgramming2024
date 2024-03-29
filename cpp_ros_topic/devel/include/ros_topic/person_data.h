// Generated by gencpp from file ros_topic/person_data.msg
// DO NOT EDIT!


#ifndef ROS_TOPIC_MESSAGE_PERSON_DATA_H
#define ROS_TOPIC_MESSAGE_PERSON_DATA_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ros_topic
{
template <class ContainerAllocator>
struct person_data_
{
  typedef person_data_<ContainerAllocator> Type;

  person_data_()
    : usia(0)
    , tinggi(0.0)
    , nama()
    , kehadiran(false)  {
    }
  person_data_(const ContainerAllocator& _alloc)
    : usia(0)
    , tinggi(0.0)
    , nama(_alloc)
    , kehadiran(false)  {
  (void)_alloc;
    }



   typedef int64_t _usia_type;
  _usia_type usia;

   typedef double _tinggi_type;
  _tinggi_type tinggi;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _nama_type;
  _nama_type nama;

   typedef uint8_t _kehadiran_type;
  _kehadiran_type kehadiran;





  typedef boost::shared_ptr< ::ros_topic::person_data_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_topic::person_data_<ContainerAllocator> const> ConstPtr;

}; // struct person_data_

typedef ::ros_topic::person_data_<std::allocator<void> > person_data;

typedef boost::shared_ptr< ::ros_topic::person_data > person_dataPtr;
typedef boost::shared_ptr< ::ros_topic::person_data const> person_dataConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_topic::person_data_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_topic::person_data_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_topic::person_data_<ContainerAllocator1> & lhs, const ::ros_topic::person_data_<ContainerAllocator2> & rhs)
{
  return lhs.usia == rhs.usia &&
    lhs.tinggi == rhs.tinggi &&
    lhs.nama == rhs.nama &&
    lhs.kehadiran == rhs.kehadiran;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_topic::person_data_<ContainerAllocator1> & lhs, const ::ros_topic::person_data_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_topic

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_topic::person_data_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_topic::person_data_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_topic::person_data_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_topic::person_data_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_topic::person_data_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_topic::person_data_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_topic::person_data_<ContainerAllocator> >
{
  static const char* value()
  {
    return "5ad8335939c8d987f5e0189e0ca2b800";
  }

  static const char* value(const ::ros_topic::person_data_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x5ad8335939c8d987ULL;
  static const uint64_t static_value2 = 0xf5e0189e0ca2b800ULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_topic::person_data_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_topic/person_data";
  }

  static const char* value(const ::ros_topic::person_data_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_topic::person_data_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 usia\n"
"float64 tinggi\n"
"string nama\n"
"bool kehadiran\n"
;
  }

  static const char* value(const ::ros_topic::person_data_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_topic::person_data_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.usia);
      stream.next(m.tinggi);
      stream.next(m.nama);
      stream.next(m.kehadiran);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct person_data_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_topic::person_data_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_topic::person_data_<ContainerAllocator>& v)
  {
    s << indent << "usia: ";
    Printer<int64_t>::stream(s, indent + "  ", v.usia);
    s << indent << "tinggi: ";
    Printer<double>::stream(s, indent + "  ", v.tinggi);
    s << indent << "nama: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.nama);
    s << indent << "kehadiran: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.kehadiran);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_TOPIC_MESSAGE_PERSON_DATA_H
