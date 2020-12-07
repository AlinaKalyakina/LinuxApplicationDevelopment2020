/* COMMENT:: guess, 1.0: Mon Dec  7 22:10:58 MSK 2020 */;
/** @file roman.h
 * Functions for converting integet to roman number representations and back.
 */
#ifndef ROMAN_H_INCLUDED
#define ROMAN_H_INCLUDED

/** Minimum possible number */
#define MIN_NUM 0
/** Maximum possible number */
#define MAX_NUM 100
/**
 * Gives strign that represents roman number 
 * 
 * @param num integer number 
 * @returns const pointer to string representing given number. If number out of interval, assert works 
 */
const char * get_roman(int num);

/**
 * Parse roman number string into integer
 * 
 * @param num roman number string
 * @returns integer representation of roman number, -1 if such representation is unknown
 */
int parse_roman(const char * num);

#endif
