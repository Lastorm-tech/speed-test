//cfg test iterations

/**
 * L1 = 10, 
 * L2 = 100,
 * L3 = 10000,
 * L4 = 100000,
 * L5 = 1000000,
 * L6 = 100000000,
 * L7 = 1000000000;
 
 SET your ITERATION range and TRYNUMBER offset, 
 -> number of cycles = ITERATION * TRYNUMBER
 -> precision of cycles = TRYNUMBER
 -> average cycles speed = ∑Ti / (ITERATION * TRYNUMBER), where T = ((ns + s * 10^5) / 1000)
**/
const unsigned int ITERATION = L1;
const unsigned int TRYNUMBER = L3;

//@GENS write here your common attributes

/** this is an example, delete the line 23 **/
std::string lz_str;

//@GENE

//@T1 <- do not delete, it's a marker
void test1()
{   
    /** this is an example, delete the line 31 **/
    lz_str += "speed";
}

//@T2 <- do not delete, it's a marker
void test2()
{
    /** this is an example, delete the line 38 **/
    lz_str.append("speed");
}
