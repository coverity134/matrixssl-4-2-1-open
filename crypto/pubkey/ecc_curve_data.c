/**
 *      @file    ecc_curve_data.c
 *      @version 91fd0f1 (tag: 4-2-1-open)
 *
 *      ECC curve data.
 */
/*
 *      Copyright (c) 2013-2018 INSIDE Secure Corporation
 *      Copyright (c) PeerSec Networks, 2002-2011
 *      All Rights Reserved
 *
 *      The latest version of this code is available at http://www.matrixssl.org
 *
 *      This software is open source; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This General Public License does NOT permit incorporating this software
 *      into proprietary programs.  If you are unable to comply with the GPL, a
 *      commercial license for this software may be purchased from INSIDE at
 *      http://www.insidesecure.com/
 *
 *      This program is distributed in WITHOUT ANY WARRANTY; without even the
 *      implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *      See the GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *      http://www.gnu.org/copyleft/gpl.html
 */
/******************************************************************************/

#include "../cryptoImpl.h"

# ifdef USE_ECC
/*
    This array holds the ecc curve settings.

    The recommended elliptic curve domain parameters over p have been given
    nicknames to enable them to be easily identified. The nicknames were
    chosen as follows. Each name begins with sec to denote ‘Standards for
    Efficient Cryptography’, followed by a p to denote parameters over p,
    followed by a number denoting the length in bits of the field size p,
    followed by a k to denote parameters associated with a Koblitz curve or an
    r to denote verifiably random parameters, followed by a sequence number.

    typedef struct {
        uint8_t     size; // The size of the curve in octets
        psCurve16_t    curveId; // IANA named curve id for TLS use
        uint8_t     isOptimized; // 1 if optimized with field parameter A=-3
        uint32_t    OIDsum; // Internal Matrix OID
        //Domain parameters
        const char *name;  // name of curve
        const char *prime; // prime defining the field the curve is in (hex)
        const char *A; // The fields A param (hex)
        const char *B; // The fields B param (hex)
        const char *order; // The order of the curve (hex)
        const char *Gx; // The x co-ordinate of the base point on the curve (hex)
        const char *Gy; // The y co-ordinate of the base point on the curve (hex)
    } psEccCurve_t;
 */
const psEccCurve_t eccCurves[] = {
# ifdef USE_SECP256R1
    {
        32,
        IANA_SECP256R1,
        1,   /* isOptimized */
        526, /* 42.134.72.206.61.3.1.7 */
        "secp256r1",
        "FFFFFFFF00000001000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFF",
        "FFFFFFFF00000001000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFC",
        "5AC635D8AA3A93E7B3EBBD55769886BC651D06B0CC53B0F63BCE3C3E27D2604B",
        "FFFFFFFF00000000FFFFFFFFFFFFFFFFBCE6FAADA7179E84F3B9CAC2FC632551",
        "6B17D1F2E12C4247F8BCE6E563A440F277037D812DEB33A0F4A13945D898C296",
        "4FE342E2FE1A7F9B8EE7EB4A7C0F9E162BCE33576B315ECECBB6406837BF51F5",
    },
# endif
# ifdef USE_SECP384R1
    {
        48,
        IANA_SECP384R1,
        1,   /* isOptimized */
        210, /* 43.129.4.0.34 */
        "secp384r1",
        "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFFFF0000000000000000FFFFFFFF",
        "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFFFF0000000000000000FFFFFFFC",
        "B3312FA7E23EE7E4988E056BE3F82D19181D9C6EFE8141120314088F5013875AC656398D8A2ED19D2A85C8EDD3EC2AEF",
        "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC7634D81F4372DDF581A0DB248B0A77AECEC196ACCC52973",
        "AA87CA22BE8B05378EB1C71EF320AD746E1D3B628BA79B9859F741E082542A385502F25DBF55296C3A545E3872760AB7",
        "3617DE4A96262C6F5D9E98BF9292DC29F8F41DBD289A147CE9DA3113B5F0B8C00A60B1CE1D7E819D7A431D7C90EA0E5F",
    },
# endif
# ifdef USE_SECP521R1
    {
        66,
        IANA_SECP521R1,
        1,   /* isOptimized */
        211, /* 43.129.4.0.35 */
        "secp521r1",
        "1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF",
        "1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC",
        "51953EB9618E1C9A1F929A21A0B68540EEA2DA725B99B315F3B8B489918EF109E156193951EC7E937B1652C0BD3BB1BF073573DF883D2C34F1EF451FD46B503F00",
        "1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA51868783BF2F966B7FCC0148F709A5D03BB5C9B8899C47AEBB6FB71E91386409",
        "C6858E06B70404E9CD9E3ECB662395B4429C648139053FB521F828AF606B4D3DBAA14B5E77EFE75928FE1DC127A2FFA8DE3348B3C1856A429BF97E7E31C2E5BD66",
        "11839296A789A3BC0045C8A5FB42C7D1BD998F54449579B446817AFBD17273E662C97EE72995EF42640C550B9013FAD0761353C7086A272C24088BE94769FD16650",
    },
# endif
# ifdef USE_BRAIN512R1
    {
        64,  /* size in octets */
        IANA_BRAIN512R1,
        0,   /* isOptimized */
        110, /* 1.3.36.3.3.2.8.1.1.13 */
        "brainpoolP512r1",
        "AADD9DB8DBE9C48B3FD4E6AE33C9FC07CB308DB3B3C9D20ED6639CCA703308717D4D9B009BC66842AECDA12AE6A380E62881FF2F2D82C68528AA6056583A48F3",
        "7830A3318B603B89E2327145AC234CC594CBDD8D3DF91610A83441CAEA9863BC2DED5D5AA8253AA10A2EF1C98B9AC8B57F1117A72BF2C7B9E7C1AC4D77FC94CA",
        "3DF91610A83441CAEA9863BC2DED5D5AA8253AA10A2EF1C98B9AC8B57F1117A72BF2C7B9E7C1AC4D77FC94CADC083E67984050B75EBAE5DD2809BD638016F723",
        "AADD9DB8DBE9C48B3FD4E6AE33C9FC07CB308DB3B3C9D20ED6639CCA70330870553E5C414CA92619418661197FAC10471DB1D381085DDADDB58796829CA90069",
        "81AEE4BDD82ED9645A21322E9C4C6A9385ED9F70B5D916C1B43B62EEF4D0098EFF3B1F78E2D0D48D50D1687B93B97D5F7C6D5047406A5E688B352209BCB9F822",
        "7DDE385D566332ECC0EABFA9CF7822FDF209F70024A57B1AA000C55B881F8111B2DCDE494A5F485E5BCA4BD88A2763AED1CA2B2FA8F0540678CD1E0F3AD80892",
    },
# endif
# ifdef USE_BRAIN384R1
    {
        48,  /* size in octets */
        IANA_BRAIN384R1,
        0,   /* isOptimized */
        108, /* 1.3.36.3.3.2.8.1.1.11 */
        "brainpoolP384r1",
        "8CB91E82A3386D280F5D6F7E50E641DF152F7109ED5456B412B1DA197FB71123ACD3A729901D1A71874700133107EC53",
        "7BC382C63D8C150C3C72080ACE05AFA0C2BEA28E4FB22787139165EFBA91F90F8AA5814A503AD4EB04A8C7DD22CE2826",
        "04A8C7DD22CE28268B39B55416F0447C2FB77DE107DCD2A62E880EA53EEB62D57CB4390295DBC9943AB78696FA504C11",
        "8CB91E82A3386D280F5D6F7E50E641DF152F7109ED5456B31F166E6CAC0425A7CF3AB6AF6B7FC3103B883202E9046565",
        "1D1C64F068CF45FFA2A63A81B7C13F6B8847A3E77EF14FE3DB7FCAFE0CBD10E8E826E03436D646AAEF87B2E247D4AF1E",
        "8ABE1D7520F9C2A45CB1EB8E95CFD55262B70B29FEEC5864E19C054FF99129280E4646217791811142820341263C5315",
    },
# endif
# ifdef USE_BRAIN256R1
    {
        32,  /* size in octets */
        IANA_BRAIN256R1,
        0,   /* isOptimized */
        104, /* 1.3.36.3.3.2.8.1.1.7 */
        "brainpoolP256r1",
        "A9FB57DBA1EEA9BC3E660A909D838D726E3BF623D52620282013481D1F6E5377",
        "7D5A0975FC2C3057EEF67530417AFFE7FB8055C126DC5C6CE94A4B44F330B5D9",
        "26DC5C6CE94A4B44F330B5D9BBD77CBF958416295CF7E1CE6BCCDC18FF8C07B6",
        "A9FB57DBA1EEA9BC3E660A909D838D718C397AA3B561A6F7901E0E82974856A7",
        "8BD2AEB9CB7E57CB2C4B482FFC81B7AFB9DE27E1E3BD23C23A4453BD9ACE3262",
        "547EF835C3DAC4FD97F8461A14611DC9C27745132DED8E545C1D54C72F046997",
    },
# endif
# ifdef USE_SECP224R1
    {
        28,
        IANA_SECP224R1,
        1,   /* isOptimized */
        209, /* 43.129.4.0.33 */
        "secp224r1",
        "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000001",
        "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFE",
        "B4050A850C04B3ABF54132565044B0B7D7BFD8BA270B39432355FFB4",
        "FFFFFFFFFFFFFFFFFFFFFFFFFFFF16A2E0B8F03E13DD29455C5C2A3D",
        "B70E0CBD6BB4BF7F321390B94A03C1D356C21122343280D6115C1D21",
        "BD376388B5F723FB4C22DFE6CD4375A05A07476444D5819985007E34",
    },
# endif
# ifdef USE_BRAIN224R1
    {
        28,  /* size in octets */
        IANA_BRAIN224R1,
        0,   /* isOptimized */
        102, /* 1.3.36.3.3.2.8.1.1.5 */
        "brainpoolP224r1",
        "D7C134AA264366862A18302575D1D787B09F075797DA89F57EC8C0FF",
        "68A5E62CA9CE6C1C299803A6C1530B514E182AD8B0042A59CAD29F43",
        "2580F63CCFE44138870713B1A92369E33E2135D266DBB372386C400B",
        "D7C134AA264366862A18302575D0FB98D116BC4B6DDEBCA3A5A7939F",
        "0D9029AD2C7E5CF4340823B2A87DC68C9E4CE3174C1E6EFDEE12C07D",
        "58AA56F772C0726F24C6B89E4ECDAC24354B9E99CAA3F6D3761402CD"
    },
# endif
# ifdef USE_SECP192R1
    {
        24,                                                 /* size in octets */
        IANA_SECP192R1,                                     /* IANA named curve ID */
        1,                                                  /* isOptimized */
        520,                                                /* 42.134.72.206.61.3.1.1 */
        "secp192r1",
        "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFFFFFFFFFFFF", /* prime */
        "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFFFFFFFFFFFC", /* A = -3 */
        "64210519E59C80E70FA7E9AB72243049FEB8DEECC146B9B1", /* B */
        "FFFFFFFFFFFFFFFFFFFFFFFF99DEF836146BC9B1B4D22831", /* order */
        "188DA80EB03090F67CBF20EB43A18800F4FF0AFD82FF1012", /* Gx */
        "07192B95FFC8DA78631011ED6B24CDD573F977A11E794811", /* Gy */
    },
# endif
    {
        0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL
    }
};

# endif /* USE_ECC */
