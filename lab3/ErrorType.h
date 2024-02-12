#ifndef __ERRORTYPE_H__
#define __ERRORTYPE_H__

/**
 * Represent an ErrorType object
 * Use to print different type of error messages
 */
enum ErrorType {
    AIRPORT_IS_FULL,
    AIRCRAFT_EXISTS_IN_AIRPORT,
    AIRCRAFT_NOT_FOUND_IN_AIRPORT,
    NULL_PTR,
};

#endif