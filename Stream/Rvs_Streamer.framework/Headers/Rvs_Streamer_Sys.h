//
//  Rvs_Sys.h
//  RVS_Stream
//
//  Created by Lvyi on 5/6/15.
//  Copyright (c) 2015 ifziv. All rights reserved.
//

#ifndef RVS_Stream_Rvs_Sys_h
#define RVS_Stream_Rvs_Sys_h

typedef  void* RVS_HANDLE;


#if defined(__cplusplus)
#define RVS_EXTERN extern "C" __attribute__((visibility("default")))
#else
#define RVS_EXTERN extern __attribute__((visibility("default")))
#endif  // defined(__cplusplus)

#if defined(__has_feature) && defined(__has_attribute)
#if __has_feature(attribute_RVS_DEPRECATED_with_message)
#define RVS_DEPRECATED_MSG_ATTRIBUTE(s) __attribute__((deprecated(s)))
#elif __has_attribute(deprecated)
#define RVS_DEPRECATED_MSG_ATTRIBUTE(s) __attribute__((deprecated))
#else
#define RVS_DEPRECATED_MSG_ATTRIBUTE(s)
#endif  // __has_feature(attribute_RVS_DEPRECATED_with_message)
#if __has_attribute(deprecated)
#define RVS_DEPRECATED_ATTRIBUTE __attribute__((deprecated))
#else
#define RVS_DEPRECATED_ATTRIBUTE
#endif  // __has_attribute(deprecated)
#else
#define RVS_DEPRECATED_ATTRIBUTE
#define RVS_DEPRECATED_MSG_ATTRIBUTE(s)
#endif  // defined(__has_feature) && defined(__has_attribute)


#endif
