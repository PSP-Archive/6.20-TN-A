#ifndef ___NID_TABLE_H___
#define ___NID_TABLE_H___

#define N_NID(x) (sizeof(x) / sizeof(OldNewNid))

typedef struct
{
    u32 old_nid;
	u32 new_nid;
} OldNewNid;

OldNewNid SysMemForKernel_nid[] =
{
    { 0x1C1FBFE7, 0xC6A782DA }, //Updated
    { 0x002BA296, 0x6FDEF86F }, //Updated
    { 0x03808C51, 0x3988900F }, //Updated
    { 0xC9805775, 0x9BAA857E }, //Updated
    { 0xEB7A74DB, 0x191C6F98 }, //Updated
    { 0x636C953B, 0x96BFE779 }, //Updated
    { 0x7B749390, 0xC2A8C491 }, //Updated
    { 0xA823047E, 0xA60B6316 }, //Updated
    { 0x55A40B2C, 0xE057A674 }, //Updated
    { 0xE6581468, 0xA25BF7A1 }, //Updated
    { 0xBB90D841, 0x20001B3C }, //Updated
    { 0x9697CD32, 0x35588461 }, //Updated
    { 0xA2A65F0E, 0x22CD6BE7 }, //Updated
    { 0x237DBD4F, 0xE5E18A99 }, //Updated
    { 0xCE5544F4, 0x6467A511 }, //Updated
    { 0x5EBE73DE, 0x138082C6 }, //Updated
    { 0x915EF4AC, 0x7BC702B2 }, //Updated
    { 0x82CCA14F, 0x51674BC8 }, //Updated
    { 0xEE867074, 0x5FBC6777 }, //Updated
    { 0xB6D61D02, 0x093DE56A }, //Updated
    { 0x2A3E5280, 0x442F5709 }, //Updated
    { 0x9D9A5BA1, 0xFEB5C72B }, //Updated
    { 0xA089ECA4, 0x18D7F644 }, //Updated
    { 0x2F808748, 0x8D34BBDA },
    { 0x1C4B1713, 0x08F96A1B }, //Updated
    { 0x0D1D8AC8, 0x93EAD67C }, //Updated
    { 0x97B18FA8, 0xCA852144 }, //Updated
    { 0xE40D3A1D, 0x1DFFBF56 }, //Updated
    { 0xCE8D3DB3, 0x040CDA4C }, //Updated
    { 0x55E4719C, 0xAAE557BF }, //Updated
    { 0x6D8E0CDF, 0x2F756CC8 }, //Updated
    { 0xC7E57B9C, 0xB00D1EC2 }, //Updated
    { 0xA262FEF0, 0x1205AE0C }, //Updated
    { 0xF91FE6AA, 0x4BFF26D9 }, //Updated
    { 0xFC114573, 0xB9796F69 }, //Updated
    { 0xDEC0A0D8, 0x031563B1 }, //Updated
    { 0x7ECBDBD9, 0xBD71F23A }, //Updated
    { 0x9C304ED7, 0xDCFF8AE5 }, //Updated
    { 0xF4390489, 0xB0ED0CCD }, //Updated
    { 0x419DB8F4, 0x02AEA33F }, //Updated
    { 0xA1ACEA31, 0xC10C3C26 }, //Updated
    { 0x7B3E7441, 0xFE305C1C }, //Updated
    { 0xE0058030, 0xEA1C5190 }, //Updated
    { 0x719792F1, 0x94AED0B5 }, //Updated
    { 0x101C3E59, 0x51963398 }, //Updated
    { 0xB2C7AA36, 0x31DFE03F }, //Updated
    { 0x6C1DCD41, 0x455CF575 }, //Updated
    { 0x5367923C, 0xCBA3E53A }, //Updated
    { 0x6CD838EC, 0xAB8A8028 }, //Updated
    { 0xCE05CCB7, 0x3699EF87 }, //Updated
    { 0xAD09C397, 0x146C2BA2 }, //Updated
    { 0x89A74008, 0xB8D6DC38 }, //Updated
    { 0x55BFD686, 0xBDD1D428 }, //Updated
    { 0xFEFC8666, 0x483237E4 }, //Updated
    { 0xD1BAB054, 0x85AE7A69 }, //Updated
    { 0x1C221A08, 0x4DF843CC }, //Updated
    { 0x2E3402CC, 0x4AA435F6 }, //Updated
    { 0x39357F07, 0xFC3E85D6 }, //Updated
    { 0x8F20C4C0, 0x6C00F0CC }, //Updated
    { 0xCF4DE78C, 0xF5780DAA }, //Updated
    { 0x41FFC7F9, 0xD17C6005 }, //Updated
    { 0x82D3CEE3, 0x9DABAF4E }, //Updated
    { 0xFC207849, 0x491942DC }, //Updated
    { 0x536AD5E1, 0x6DD87F6B }, //Updated
    { 0xDFAEBD5B, 0xD0DBFFE7 }, //Updated
    { 0x7BE95FA0, 0xFEA10418 }, //Updated
    { 0xFE8DEBE0, 0xCCD58B8B }, //Updated
    { 0xF6C10E27, 0xA75DC8CE }, //Updated
    { 0xE0645895, 0x75A7EA2D }, //Updated
    { 0x1890BE9C, 0xF4C96DB4 }, //Updated
    { 0x03072750, 0xAF8CBF62 }, //Updated
    { 0x811BED79, 0x17BF724F }, //Updated
    { 0xCDA3A2F7, 0xA4AC3934 }, //Updated
    { 0x960B888C, 0x55C21972 }, //Updated
    { 0xCBB05241, 0x7EF1DC3C }, //Updated
    { 0x2269BFA2, 0x2DC2E222 }, //Updated
    { 0xCD617A94, 0xAB5E85E5 }, //Updated
    { 0xF77D77CB, 0x374DF838 }, //Updated
    { 0x38495D84, 0x2E0F38E5 }, //Updated
    { 0x6373995D, 0x864EBFD7 }, //Updated
    { 0x29A5899B, 0xC5485286 }, //Updated
    { 0x071D9804, 0x13DC1D8E }, //Updated
    { 0x02786087, 0x00E0050D }, //Updated
    { 0x1F7F7F40, 0x00E0050D }, //Updated
    { 0x049CC735, 0x1B03DBB9 }, //Updated
    { 0x39351245, 0x5AE912B5 }, //Updated
    { 0xD2E3A399, 0xEEB65C76 }, //Updated
    { 0x4852F8DD, 0xEF66EEC6 }, //Updated
    { 0x4EC43DC4, 0x906D863A }, //Updated
    { 0x1F01A9E2, 0x3B560EE6 }, //Updated
    { 0xB9F8561C, 0xB0CC8D87 }, //Updated
    { 0x9452B542, 0x361DC8C0 }, //Updated
    { 0x3FC9AE6A, 0xFE9BC18B }, //Updated
    { 0x452E3696, 0x957A966D }, //Updated
    { 0x95F5E8DA, 0x98ACDE01 }, //Updated
    { 0xEF2EE8C1, 0x2F15F149 }, //Updated
};

OldNewNid KDebugForKernel_nid[] =
{
    { 0xA2983280, 0x56B63535 }, //Updated
    { 0x2FF4E9F9, 0xEC5AE038 }, //Updated
    { 0x5282DD5E, 0x44599648 }, //Updated
    { 0xEE75658D, 0x9023AB67 }, //Updated
    { 0x428A8DA3, 0x98A23ABC }, //Updated
    { 0x72E6B3B8, 0x274F1548 }, //Updated
    { 0xA216AE06, 0xD9DB4F02 }, //Updated
    { 0x333DCEC7, 0x67AAE03C }, //Updated
    { 0x9B868276, 0xE50EB8AE }, //Updated
    { 0x8B041DFB, 0xAED9BE14 }, //Updated
    { 0xE7A3874D, 0x8F99B08A }, //Updated
    { 0xAFB8FC80, 0x959D4C09 }, //Updated
    { 0x23906FB2, 0x2F753063 }, //Updated
    { 0x9F8703E4, 0xC87C49CF }, //Updated
    { 0xFFD2F2B9, 0xAFDEF5C1 }, //Updated
    { 0xE146606D, 0x8F7CE42D }, //Updated
    { 0x7CEB2C09, 0x681C1EEA }, //Updated
    { 0x5CE9838B, 0x93701FDB }, //Updated
    { 0x66253C4E, 0xAA33F12F }, //Updated
    { 0xDBB5597F, 0x46750633 }, //Updated
    { 0xE6554FDA, 0xC741642A }, //Updated
    { 0xB9C643C9, 0xEB0759EF }, //Updated
    { 0x7D1C74F0, 0x295865B1 }, //Updated
    { 0xA126F497, 0x62469B57 }, //Updated
    { 0xB7251823, 0x715A5348 }, //Updated
    { 0x24C32559, 0x93F5D2A6 }, //Updated
};

OldNewNid LoadCoreForKernel_nid[] =
{
    { 0x99A695F0, 0xCD1D28E3 }, //Updated
    { 0x9BAF90F6, 0x3E5F5629 }, //Updated
    { 0x0E760DBA, 0x8C712A03 }, //Updated
    { 0x7E63F86D, 0xF62D0F30 }, //Updated
    { 0xB370DF29, 0xA5E8A07F }, //Updated
    { 0x5248A98F, 0xD5B046F0 }, //Updated
    { 0x5873A31F, 0x79970B0B }, //Updated
    { 0x0B464512, 0x4CF715C5 }, //Updated
    { 0x0DE1F600, 0x3922A067 }, //Updated
    { 0xC0913394, 0x1D665D6D }, //Updated
    { 0x616FCCCD, 0x371962BE }, //Updated
    { 0xACE23476, 0xB6F01A3C }, //Updated
    { 0xEC20C661, 0x593A3FD9 }, //Updated
    { 0xCDCAA8B2, 0x8F8F99D1 }, //Updated
    { 0xCD0F3BAC, 0x7A0FB6D6 }, //Updated
    { 0x8D8A8ACE, 0x1591CFB1 }, //Updated
    { 0x74CF001A, 0x631EB12B }, //Updated
    { 0x05D915DB, 0x0FEC2F68 }, //Updated
    { 0x52A86C21, 0xF9FD7790 }, //Updated
    { 0x6B2371C2, 0xA3035783 }, //Updated
    { 0xAFF947D4, 0x24F00493 }, //Updated
    { 0xAE7C6E76, 0x602BF42A }, //Updated
    { 0xCF8A41B1, 0xBEF0A05E }, //Updated
    { 0xFB8AE27D, 0x452C5524 }, //Updated
    { 0xA6D40F56, 0x141827CE }, //Updated
    { 0xCCE4A157, 0x77E8F516 }, //Updated
    { 0x929B5C69, 0xFB770EC0 }, //Updated
    { 0x2952F5AC, 0x693A6BD6 }, //Updated
    { 0xD8779AC6, 0x59203AED }, //Updated
    { 0x4440853B, 0x4B4306C2 }, //Updated
    { 0xFA3101A4, 0x8409BAA8 }, //Updated
    { 0x0C0D8B7F, 0x7A0890AD }, //Updated
    { 0xC99DD47A, 0x1B107A36 }, //Updated
    { 0x3BB7AC18, 0x60BC436F }, //Updated
    { 0x7BE1421C, 0xB0466E46 }, //Updated
    { 0xBF983EF2, 0xB95FA50D }, //Updated
    { 0x7068E6BA, 0x6E8B6AB6 }, //Updated
    { 0xB4D6FECC, 0xF96F36C8 }, //Updated
    { 0x54AB2675, 0x7B30197C }, //Updated
};

OldNewNid ExceptionManagerForKernel_nid[] =
{
    { 0x5A837AD4, 0x71286CF4 }, //Updated
    { 0x565C0B0E, 0x557FBABB }, //Updated
    { 0x1AA6CFFA, 0xC0BC60E9 }, //Updated
    { 0x291FF031, 0x85F02133 }, //Updated
    { 0x3FB264FC, 0x56198384 }, //Updated
    { 0xDF83875E, 0x014FD1D1 }, //Updated
    { 0xFC26C354, 0x7DDFBCC7 }, //Updated
};

OldNewNid InterruptManagerForKernel_nid[] =
{
    { 0x85F7766D, 0xD24AE49D }, //Updated
    { 0x15894D0B, 0xD2274728 }, //Updated
    { 0xB5A15B30, 0xED293043 },
    { 0x43A7BBDC, 0xCCC5A332 }, //Updated
    { 0x750E2507, 0xC34D4BFF },
    { 0x494D6D2B, 0xEC5485ED }, //Updated
    { 0x55242A8B, 0xE3CDA797 }, //Updated
    { 0xCDC86B64, 0xEC51802D }, //Updated
    { 0xD6878EB6, 0xFEE218CE }, //Updated
    /*{ 0xF4454E44, 0x4B67E78E },
    { 0xCA04A2B9, 0xCFFA1857 },
    { 0x5CB5A78B, 0x68C49DDF },
    { 0x7860E0DC, 0x119C5FDA },
    { 0x36B1EF81, 0x060BEA41 },*/
    { 0x0FC68A56, 0x667D2693 }, //Updated
    { 0x07E138EE, 0x528FD951 },
    { 0xD8410DE6, 0x79EE281A }, //Updated
    { 0x2CD783A1, 0x8C57E272 },
    { 0x27BC9A45, 0x47B6E6B7 }, //Updated
    { 0x0E224D66, 0x3AB4955A }, //Updated
    { 0x35634A64, 0x0371FA94 }, //Updated
    { 0xF4D443F3, 0x580DDADD }, //Updated
    { 0x8B61808B, 0xAC9306F0 }, //Updated
    { 0x8DC2BAEF, 0x114435E5 }, //Updated
    { 0x8A389411, 0xC03C8D51 }, //Updated
    { 0xFC4374B8, 0x2D70650B }, //Updated
    { 0x7AD28215, 0x1C7250CC },
    { 0x53991063, 0x9918DEF9 },
    { 0x468BC716, 0x0CE5174E },
    { 0x00B6B0F3, 0x5F3525D5 }, //Updated
    { 0x0B907DBC, 0xF952C56F }, //Updated
    { 0x7A05D976, 0x80EE1E2E }, //Updated
    { 0x7EF7500F, 0xB8D11C47 }, //Updated
    { 0x20804B41, 0xD16BF06B }, //Updated
    { 0x2DC9709B, 0x53F5A3F8 }, //Updated
    { 0xE9E652A9, 0x247EBFCB }, //Updated
    { 0x05E9D6C4, 0x36A721FB }, //Updated
    { 0xD63F3B31, 0xA359F4BA }, //Updated
    { 0x43CD40EF, 0xBBE3C1A7 }, //Updated
    { 0xDD55A192, 0x9A507C55 }, //Updated
    { 0x72CE22E8, 0x157ADE6A }, //Updated
};

OldNewNid IoFileMgrForKernel_nid[] =
{
    { 0xA905B705, 0xEB5BE7EC }, //Updated
    { 0x3C54E908, 0xF0AD3C72 }, //Updated
    { 0xCB0A151F, 0x9D5CDC31 }, //Updated
    { 0x73B7671F, 0xDC30BB19 }, //Updated
    { 0x9B86630B, 0x4F663EBF }, //Updated
    { 0x30E8ABB3, 0xF2990AC6 }, //Updated
    { 0x411106BA, 0x0AB86E5D }, //Updated
    { 0x5216CE3F, 0xE5307197 }, //Updated
    { 0x42F954D4, 0xB2C5D86F }, //Updated
    { 0xBD17474F, 0x6CE0E5F0 }, //Updated
};

OldNewNid ModuleMgrForKernel_nid[] =
{
    { 0x6DE9FF11, 0xB691CB9F }, //Updated
    { 0xA1A78C58, 0x7F9670CF }, //Updated
    { 0x896C15B6, 0xD2FB2722 }, //Updated
    { 0x92EDEBD0, 0xB029065E }, //Updated
    { 0x1B91F6EC, 0xADAE7610 }, //Updated
    { 0x6723BBFF, 0xF8CA0D9D }, //Updated
    { 0x49C5B9E1, 0x9D790CD9 }, //Updated
    { 0xECC2EAA9, 0x42C48848 }, //Updated
    { 0xF07E1A2F, 0x7933CC33 }, //Updated
    { 0x0CE03872, 0xD293E707 }, //Updated
    { 0x245B698D, 0xD87F08E4 }, //Updated
    { 0xA4370E7C, 0x329C89DB }, //Updated
    { 0x91B87FAE, 0xB0752D7D }, //Updated
    { 0x977DE386, 0xE3CCC6EA }, //Updated
    { 0xB7F46618, 0x087AE64D },
    { 0x3E4FEDDC, 0xED5094E2 }, //Updated
    { 0xAB77DC5A, 0xA035AADA }, //Updated
    { 0x5C88479B, 0x2124FEC7 }, //Updated
    { 0x50F0C1EC, 0xDF8FFFAB }, //Updated
    { 0xD1FF982A, 0xAAFA90C2 }, //Updated
    { 0xD675EBB8, 0x75ECB8BA }, //Updated
    { 0x644395E2, 0x4392903C }, //Updated
    { 0x748CBED9, 0x8F38EBE9 }, //Updated
    { 0xF0A26395, 0xB7CFD5AD }, //Updated
    { 0xD8B73127, 0x0F3F0B4C }, //Updated
    { 0x9F3AD1E9, 0x8E9C873C }, //Updated
    { 0xCE70664B, 0x5226F362 }, //Updated
    { 0xB5DDABD3, 0xDEE14448 }, //Updated
    { 0xF0CAC59E, 0xBB6E2BCA }, //Updated
    { 0x667C1174, 0x5EBE54F1 }, //Updated
    { 0xBA889C07, 0x5352C26C }, //Updated
    { 0x5799EE32, 0x9E4C362D }, //Updated
    { 0x53CA70EE, 0x90F5533C }, //Updated
    { 0xEF7A7F02, 0x76D0B981 }, //Updated
    { 0x2E0911AA, 0x9CEB18C4 }, //Updated
    { 0x2BE4807D, 0xB9FAD518 }, //Updated
    { 0xCC1D3699, 0xB751A9DE }, //Updated
    { 0x04B7BD22, 0x6620C340 }, //Updated
    { 0x54D9E02E, 0xB490529C }, //Updated
    { 0x2BE2B17E, 0x42F022E4 }, //Updated
    { 0x5F0CC575, 0x6100F075 }, //Updated
    { 0xA6E8C1F5, 0x0D4B0221 }, //Updated
    { 0xB49FFB9E, 0xCE234D4A }, //Updated
    { 0x25E1F458, 0xDAC8A7B3 }, //Updated
    { 0x74690AEB, 0x748EC4A6 }, //Updated
    { 0xF80F3C96, 0xF4B7909C }, //Updated
    { 0xF7E46A72, 0xA63A565A }, //Updated
    { 0x61EC6AB0, 0xDBE7524B }, //Updated
};

OldNewNid LoadExecForKernel_nid[] =
{
    { 0xA3D5E142, 0xAEFEF0F4 }, //Updated
    { 0x4AC57943, 0xB5CE3204 }, //Updated
    { 0x62A27008, 0x63BB2F2C }, //Updated
    { 0xD3D13800, 0x596ABD6B }, //Updated
    { 0x1B97BDB3, 0x73BAD4F8 }, //Updated
    { 0x821BE114, 0xD364D324 }, //Updated
    { 0x7B7C47EF, 0x00FC0987 }, //Updated
    { 0x6D8D3A3A, 0x9D1ED0DF }, //Updated
    { 0x015DA036, 0x32224187 }, //Updated
    { 0x4F41E75E, 0x0C12D5DC }, //Updated
    { 0x31DF42BF, 0x783EA19F }, //Updated
    { 0x28D0D249, 0x254F01CB }, //Updated
    { 0x70901231, 0xE09DAFDC }, //Updated
    { 0x061D9514, 0xEFA048F1 }, //Updated
    { 0xB7AB08DA, 0xD1DFD7A6 }, //Updated
    { 0x6D302D3D, 0x29413885 }, //Updated
    { 0x15EB8575, 0xE717E255 }, //Updated
    { 0x659188E1, 0xB848CC2C }, //Updated
    { 0x11412288, 0xFABD21E5 }, //Updated
    { 0xD9739B89, 0x71EF3793 }, //Updated
};

OldNewNid sceDdr_driver_nid[] =
{
    { 0x286E1372, 0x37B1BD46 }, //Updated
    { 0x6078F911, 0xEF5E4465 }, //Updated
    { 0xB5694ECD, 0xFAC28535 }, //Updated
    { 0x5B5831E5, 0xD48CC758 }, //Updated
    { 0xF23B7983, 0xBD40FC26 }, //Updated
    { 0x655A9AB0, 0xCDBED410 }, //Updated
    { 0x6955346C, 0x8D5170F3 }, //Updated
    { 0x0DC43DE4, 0xF19FD587 }, //Updated
    { 0xD7C6C313, 0x0B4E8A52 }, //Updated
    { 0x91CD8F94, 0x9B29E314 }, //Updated
    { 0x888129E8, 0xB8D2E273 }, //Updated
    { 0x7251F5AB, 0xD8910A05 }, //Updated
    { 0x4CE55E76, 0x25AB44F3 }, //Updated
};

OldNewNid sceDmacplus_driver_nid[] =
{
    /*{ 0xC748491D, 0x78ED5F43 },
    { 0xA7B05225, 0x61989D3A },
    { 0xBF939272, 0xA258A023 },
    { 0x6AA3D654, 0x6BB2E47C },
    { 0x0DA570C1, 0x1068393E },
    { 0xDF32F547, 0xBF888BEC },
    { 0xE6219C61, 0x3B3C6252 },
    { 0x853C5EC6, 0xE7580E49 },
    { 0xD49A5922, 0x3E868CEE },
    { 0xFE3F3228, 0x8472BB23 },
    { 0x42BEB349, 0x0B1C48AA },
    { 0x29B50A82, 0xBA1605D2 },
    { 0x8AE579CD, 0xFFF6EE05 },
    { 0x241601AE, 0x464AB3C1 },
    { 0xF8C7C180, 0xCBE11C48 },
    { 0xCDB039A7, 0xBB77E17A },
    { 0x576522BC, 0x7321EDEE },
    { 0x1D73DDA8, 0x6BB9BD45 },
    { 0x74323807, 0x86EAC84A },
    { 0x3A98EE05, 0x0A40EF79 },
    { 0xBEC10779, 0x6292E01D },
    { 0x7AAE5443, 0x983FABB2 },
    { 0x5E32C8AF, 0x7D7BE745 },
    { 0xB2EFA681, 0x960D7B8A },
    { 0x4B980588, 0xFBE5DE3E },
    { 0x3438DA0B, 0x8AA7F020 },
    { 0x58DE4914, 0x915A917C },
    { 0xFD8B15BC, 0x84EBD5B1 },
    { 0xF7DEC189, 0x4391D45C },
    { 0xC5B75E09, 0x975BB7E2 },
    { 0xBE693828, 0x21DA182B },
    { 0xAB49D2CB, 0x1D65E667 },
    { 0x1F5A80D0, 0x54A776A3 },
    { 0xD1E1567E, 0x3A5F9CC1 },
    { 0x2D5940FF, 0x24B3E74C },
    { 0x3DB353DB, 0xA05CA13D },
    { 0x28558DBF, 0x50FCAA20 },
    { 0xFD183BCF, 0x48632A5F },
    { 0xB6592A56, 0x4DB8CA36 },
    { 0x4F1B8D26, 0x5FEC19EE },
    { 0xC3236D69, 0xC751F860 },
    { 0xC8336549, 0xB94CB1D4 },
    { 0x58C380BB, 0x8438DB83 },
    { 0x1E7483D0, 0xA79EE6F6 },
    { 0x168836CF, 0x0F01FE4A },
    { 0xD0464B29, 0x8B6B73F9 },
    { 0xFEE3392C, 0x539A58C9 },
    { 0x9393B40D, 0x4ABEFBC1 },
    { 0x6D4F8BD7, 0xF5F2AD5E },
    { 0x78A55D62, 0xA836FBEA },
    { 0xC7D33466, 0xAC024305 },
    { 0x410ED0DD, 0x9C57AB36 },
    { 0x97DCBBBF, 0x7A9001AF },*/
};

OldNewNid sceGpio_driver_nid[] =
{
    { 0xCA8BE2EA, 0xD5469E56 }, //Updated
    { 0x37C8DADC, 0x317D9D2C }, //Updated
    { 0xF856CE46, 0xDB4F5CE2 }, //Updated
    { 0x95135905, 0xE7BDAF50 }, //Updated
    { 0x785206CD, 0xB0D23234 }, //Updated
    { 0x31F34AE6, 0x856D950A }, //Updated
    { 0xBE77D1D0, 0x7AD284FD }, //Updated
    { 0xC6928224, 0xE8A497DE }, //Updated
    { 0x6B38B826, 0xEBF28F41 }, //Updated
    { 0x5691CEFA, 0xD2A8B1B5 }, //Updated
    { 0x2CDC8EDC, 0xEF344659 }, //Updated
    //{ 0x4250D44A, 0xA908E0BE },
};

OldNewNid sceSysreg_driver_nid[] =
{
    { 0xC29D614E, 0x9EF98522 }, //Updated
    { 0xDC6139A4, 0x3B286D7A }, //Updated
    { 0xDE59DACB, 0x97EA6913 }, //Updated
    { 0x2DB0EB28, 0x2D858336 }, //Updated
    { 0x26283A6F, 0x3CC1D73F }, //Updated
    { 0xA374195E, 0x2F353BF5 }, //Updated
    { 0xD20581EA, 0xA9A2F237 }, //Updated
    { 0x7558064A, 0x67557011 }, //Updated
    { 0x9BB70D34, 0x119647A7 }, //Updated
    { 0xFD6C562B, 0x85C424F9 }, //Updated
    { 0xCD4FB614, 0xDA2E7D06 }, //Updated
    { 0x69EECBE5, 0xED6EF130 }, //Updated
    { 0xF5B80837, 0xC572A362 }, //Updated
    { 0x8075303F, 0x5F01289B }, //Updated
    { 0x00C2628E, 0xE6A812AA }, //Updated
    { 0xEC4BF81F, 0xF81EC5B9 }, //Updated
    { 0x8A7F9EB4, 0xF7A8BFA5 }, //Updated
    { 0xC32F2491, 0x43EEDE50 }, //Updated
    { 0xA23BC2C4, 0xE40DC039 }, //Updated
    { 0xF5EA8570, 0x1CAB8282 }, //Updated
    { 0x3E961C02, 0x48546F11 }, //Updated
    { 0xACFA3764, 0xB03747DB }, //Updated
    { 0x44F6CDA7, 0xEF64EFDD }, //Updated
    { 0x158AD4FC, 0xF6922705 }, //Updated
    { 0x4D4CE2B8, 0xDF06373E }, //Updated
    { 0x789BD609, 0x9EBD0CD2 }, //Updated
    { 0x391CE1C0, 0x6637667D }, //Updated
    { 0x82D35024, 0x5AB2CF90 }, //Updated
    { 0xAF904657, 0x739A33F0 }, //Updated
    { 0x438AECE9, 0xA3C7B0C1 }, //Updated
    /*{ 0x678AD3ED, 0x3A14B278 },
    { 0x168C09B8, 0xB595FC22 },
    { 0x7E7EBC20, 0xE74CB850 },
    { 0xA265C719, 0x5ECA49E4 },*/
    { 0x4F5AFBBE, 0x0FE3B0D7 }, //Updated
    { 0x845DD1A6, 0x2AF6987B }, //Updated
    { 0x3E216017, 0xBA3FADB4 }, //Updated
    { 0xBFBABB63, 0x313DD64A }, //Updated
    { 0x4716E71E, 0x3F36F3B1 }, //Updated
    { 0x826430C0, 0x7F2571B7 }, //Updated
    { 0x7CC6CBFD, 0x1B6F77C0 }, //Updated
    { 0xEE6B9411, 0xE95E59A1 }, //Updated
    { 0x63B9EB65, 0xA8235369 }, //Updated
    { 0xE1AA9788, 0x1663DA05 }, //Updated
    { 0xAA63C8BD, 0xE7849809 }, //Updated
    /*{ 0x054AC8C6, 0xF9A652BC },
    { 0xE45BED6A, 0x97B76F89 },
    { 0x681B35C4, 0x58B2671B },
    { 0xE321F41A, 0xC367C076 },
    { 0x4D2FFC60, 0xC03903EE },
    { 0x6B01D71B, 0xAFD7C10B },
    { 0xFC186A83, 0xBD89766B },
    { 0xB59DB832, 0x3616B538 },
    { 0x9155812C, 0xFC42CD72 },
    { 0xDA4FCA1D, 0x7E046110 },
    { 0x228A73E1, 0x4F9452D7 },
    { 0x31154490, 0x6CD41073 },
    { 0x8E2D835D, 0x3AAE2AE9 },
    { 0xE8533DCA, 0x9C89F935 },
    { 0xF6D83AD0, 0x036D4A59 },
    { 0xA9CD1C1F, 0x823FFD7A },
    { 0x2F216F38, 0xE2412D26 },
    { 0xA24C242A, 0xF092AED8 },
    { 0xE89243BE, 0x280F9241 },
    { 0x7DCA8302, 0x8684E7A1 },
    { 0x45225F8F, 0x03BD35E5 },
    { 0xD74D3AB6, 0xC0BC0E36 },
    { 0xAD7C4ACB, 0x4ACB2BB3 },
    { 0xDC68A93F, 0x04839CA2 },
    { 0x94B0323C, 0x917F9660 },
    { 0xE3AECFFA, 0x2E9CF295 },
    { 0x3BBD0C0C, 0xE987E988 },
    { 0xC1DA05D2, 0x7A154A45 },
    { 0xDE170397, 0xCA84A2D9 },
    { 0x38EC3281, 0xC60904D4 },
    { 0xBC68D9B6, 0x03E84901 },
    { 0xA3C8E075, 0xB5CD678F },
    { 0x79338EA3, 0x463B488C },
    { 0xCADB92AA, 0x421E5DCF },
    { 0xD74F1D48, 0x86D9213D },
    { 0x18172C6A, 0x9FBCA4D0 },
    { 0x63B1AADF, 0xBEF287D5 },
    { 0xF74F14E9, 0xFF6D37E7 },
    { 0xBB26CF1F, 0x410C74F7 },
    { 0x8E2FB536, 0x3841D7C8 },
    { 0x0436B60F, 0x23944179 },
    { 0x58F47EFD, 0x6D204F2A },
    { 0xF844DDF3, 0xE46A0890 },
    { 0x29A119A1, 0x77B582E9 },
    { 0x7A5D2D15, 0x6B5C5FD0 },
    { 0x25B0AC52, 0x80995BB5 },
    { 0x8B95C17F, 0xFB40B1AA },
    { 0xCCF911C0, 0x3F0DF46D },
    { 0xB627582E, 0x217316F7 },
    { 0x1E9C3607, 0xC0D33340 },
    { 0x55B18B84, 0x64C2D131 },
    { 0x2112E686, 0xACA3F3A3 },
    { 0x7B9E9A53, 0x19DF2827 },
    { 0x7BDF0556, 0x02A1F862 },
    { 0x8D0FED1E, 0x2FCFA7CD },
    { 0xA46E9CA8, 0xE440DC4A },
    { 0x633595F2, 0x12EF2C08 },
    { 0x32471457, 0x0C3CFD86 },
    { 0x692F31FF, 0x7911A536 },
    { 0xFFEB6E00, 0xF464A3D9 },
    { 0x87C2BA20, 0x8D4FE210 },
    { 0xD43E98F6, 0x49B453CB },
    { 0xBF91FBDA, 0x36BBA207 },
    { 0x36A75390, 0xBA43633B },
    { 0x61BFF85F, 0xEEE7B082 },
    { 0x9FC87ED4, 0x461B8077 },
    { 0x8BE2D520, 0x0E6301D0 },
    { 0xB08A4E85, 0xF03852E0 },
    { 0xA41929DA, 0x9CE69EC1 },
    { 0xE88B77ED, 0xF287DB37 },
    { 0x312F9419, 0x0BF6F901 },
    { 0x844AF6BD, 0x17B132D5 },
    { 0xB21B6CBF, 0x9AFD029D },
    { 0xB4560C45, 0xDA1CD053 },
    { 0x1969E840, 0xB93CCA2B },
    { 0x1D382514, 0x262667F9 },
    { 0x03340297, 0xE46031A1 },
    { 0x9100B4E5, 0x923509A1 },
    { 0x1E18EA43, 0x8FA2F8C0 },
    { 0x833E6FB1, 0x7E94B309 },
    { 0x8CE2F97A, 0xAE32DCF5 },
    { 0x0A83FC7B, 0x48869494 },
    { 0x3EA188AD, 0x94A99040 },*/
    { 0x4EE8E2C8, 0x8F224A0F }, //Updated
    { 0x083F56E2, 0x787CCE85 }, //Updated
    { 0x7C5B543C, 0xBBE75ABD }, //Updated
    /*{ 0x5664F8B5, 0x0D2BE098 },
    { 0x44704E1D, 0xB97B7828 },
    { 0x584AD989, 0x3A930268 },
    { 0x377F035F, 0xAB1EA306 },
    { 0x0EA487FA, 0x030EBAD6 },
    { 0xF4811E00, 0xF73DDE93 },
    { 0x7234EA80, 0xD5F04B96 },
    { 0x77DED992, 0x9B2871A8 },
    { 0x6879790B, 0x3160E8A2 },
    { 0xCD0F6715, 0x12DDDF43 },
    { 0xF3443B9A, 0x7F734EE7 },
    { 0x53A6838B, 0xFF39996C },*/
    { 0xBB3623DF, 0xA0F3053B }, //Updated
    { 0xDCA57573, 0x81667490 }, //Updated
    { 0x25673620, 0x7ADF93F1 }, //Updated
    { 0xEE8760C6, 0x91143B9B }, //Updated
    { 0xAB3185FD, 0x73DF64ED }, //Updated
    { 0x136E8F5A, 0xC5076887 }, //Updated
    { 0xA9997109, 0x97EA6913 }, //Updated
    { 0x76220E94, 0x2D858336 }, //Updated
    { 0x3199CF1C, 0xEF64EFDD }, //Updated
    { 0x07881A0B, 0xF6922705 }, //Updated
};

OldNewNid sceSyscon_driver_nid[] =
{
    { 0x64FA0B22, 0xA0BA861F }, //Updated
    { 0x58531E69, 0x70B4B7D9 }, //Updated
    { 0xAD555CE5, 0x17B5F203 }, //Updated
    { 0xF281805D, 0x235C7D1B }, //Updated
    { 0xA068B3D0, 0x4BAEC2F6 }, //Updated
    { 0xE540E532, 0x76986BED }, //Updated
    { 0x4AB44BFC, 0x6B8C9E3F }, //Updated
    { 0xBBFB70C0, 0x9EC42912 }, //Updated
    { 0x805180D1, 0x75867DAD }, //Updated
    { 0xA8E34316, 0x97E67774 }, //Updated
    { 0x53072985, 0xFDEA1FB6 }, //Updated
    { 0xF9193EC3, 0xE5087D50 }, //Updated
    { 0x04EEFD03, 0x1AA6CBBA },
    { 0x88FDB279, 0x195C1E27 }, //Updated
    { 0xBAAECDF8, 0xB1A756B3 }, //Updated
    { 0x7479DB05, 0xA6E2325E }, //Updated
    { 0x6848D817, 0x6E7D63DD }, //Updated
    //{ 0x2EE82492, 0x2EE82492 },
    { 0xFC32141A, 0xAE3CD6FD }, //Updated
    { 0xF775BC34, 0xDCA038A1 }, //Updated
    { 0xA9AEF39F, 0xC25BB6C4 }, //Updated
    { 0x25F47F96, 0xE143D30E }, //Updated
    { 0xC4D66C1D, 0x83CB6732 },
    { 0xC7634A7A, 0x23EC219F }, //Updated
    { 0x7A805EE4, 0x77877E75 }, //Updated
    { 0x6C911742, 0x4B3EC953 }, //Updated
    { 0xE9FF8226, 0x49CA079D }, //Updated
    { 0x882F0AAB, 0x2675D6DA }, //Updated
    { 0x00E7B6C2, 0x0FD370D9 }, //Updated
    { 0x44439604, 0x76294748 }, //Updated
    { 0x91E183CB, 0x9E5CAC98 }, //Updated
    { 0xBE27FE66, 0x1F27CA6D }, //Updated
    { 0x1A08CD66, 0x4ADD8A39 },
    { 0x19D5A97A, 0x14400A9A }, //Updated
    { 0xE5E35721, 0xF7E9487A }, //Updated
    { 0x01677F91, 0x4F3581B0 }, //Updated
    { 0x09721F7F, 0x3D83B935 }, //Updated
    { 0x99BBB24C, 0x3B4D7F65 }, //Updated
    { 0xF0ED3255, 0xB757C11D }, //Updated
    { 0xA975F224, 0x9F5E95F1 }, //Updated
    { 0x9C4266FC, 0x53CB4AAB }, //Updated
    { 0x3987FEA3, 0x91167903 }, //Updated
    { 0xEAB13FBE, 0x4EB03528 },
    { 0xC5075828, 0x027785AD }, //Updated
    { 0x3C6DB1C5, 0x3ACF24BE }, //Updated
    { 0xB2558E37, 0x2404C0E1 }, //Updated
    { 0x9478F399, 0xDAE67501 }, //Updated
    { 0x6A53F3F8, 0xC7D9E65C }, //Updated
    { 0xFA4C4518, 0x7EC5EA10 }, //Updated
    { 0xE448FD3F, 0x6BC89A77 }, //Updated
    { 0x70C10E61, 0xCAF3198C }, //Updated
    { 0x8BDEBB1E, 0x420B593D }, //Updated
    { 0x373EC933, 0x067EA5AF }, //Updated
    { 0x82861DE2, 0xDB5D6CDE }, //Updated
    { 0x876CA580, 0x86780127 }, //Updated
    { 0x71135D7D, 0x4D31FDB9 }, //Updated
    { 0x7CBD4522, 0xA9C193D4 }, //Updated
    { 0x284FE366, 0x8AD2A537 }, //Updated
    { 0x75025299, 0xD6365013 }, //Updated
    { 0xB5105D51, 0x3250A1E1 }, //Updated
    { 0xD5340103, 0x9CC9302D }, //Updated
    { 0xB71B98A8, 0xC9E8A328 }, //Updated
    { 0x87671B18, 0xB593267E }, //Updated
    { 0x75D22BF8, 0xEE57D957 }, //Updated
    { 0x4C539345, 0xEABC0F0A }, //Updated
    { 0x4C0EE2FA, 0xD617DFDB }, //Updated
    { 0x08DA3752, 0x68C6A2D6 }, //Updated
    { 0x34C36FF9, 0xE30280DA }, //Updated
    { 0xD653E02E, 0x5B3E7272 }, //Updated
    { 0x565EF519, 0xE871BDE9 }, //Updated
    { 0x2B9E6A06, 0x23DA2802 }, //Updated
    { 0x5FF1D610, 0xDC37B6FF }, //Updated
    { 0x9E6E060F, 0x62012EAF }, //Updated
    { 0xE00BFC9E, 0x5FD04874 }, //Updated
    { 0xC8D97773, 0x64184899 }, //Updated
    { 0x3357EE5C, 0x6E9ABA7F }, //Updated
    { 0x32CFD20F, 0xA5F9FCB1 },
    { 0xEC0DE439, 0xC01768C4 }, //Updated
    { 0xEA5B9823, 0x0D7477A5 }, //Updated
    { 0xE20D08FE, 0xBD0257BB }, //Updated
    { 0xE0DDFE18, 0x5DED813F }, //Updated
    { 0xBDA16E46, 0x801A15E4 }, //Updated
    { 0xA6776FB4, 0xB1386840 }, //Updated
    { 0xF6BB4649, 0x475743E5 }, //Updated
    { 0x71AE1BCE, 0x8844B5EE }, //Updated
    { 0xF953EF93, 0x8203D89D }, //Updated
    { 0x7016161C, 0xBEDA2264 },
    { 0xF9FDAFA5, 0xC47642F7 },
    { 0x56A73EDD, 0xA2840D70 }, //Updated
    { 0x48AB0E44, 0x8356229C }, //Updated
    { 0x628F2351, 0x9141E498 }, //Updated
    { 0xEC37C549, 0xBB56F7CD }, //Updated
    { 0x051186F3, 0x71C7E788 }, //Updated
    { 0xCE76F93E, 0xA85C2DA9 }, //Updated
    { 0x8EDF1AD7, 0xCD4741CB }, //Updated
    { 0xEE81C5B1, 0x33F0AEDF }, //Updated
    { 0x8DDA4CA6, 0x2CE5E02E }, //Updated
    { 0x52B74B6C, 0x9301E1B1 }, //Updated
    { 0x1B17D3E3, 0xDF5E7FA8 }, //Updated
    { 0x5F19C00F, 0xF09C2BF3 }, //Updated
    { 0x3C739F57, 0x89C87536 }, //Updated
    { 0x14909C63, 0xFB155B49 }, //Updated
    { 0x72EDA9AF, 0x90DDB37B }, //Updated
    { 0xC68F1573, 0x12AFA8CB }, //Updated
    { 0x05727A0B, 0xA53A997C }, //Updated
    { 0x7C8A5503, 0xC0CA6581 }, //Updated
    { 0x2C03E53E, 0xA75E169B }, //Updated
    { 0xBF458F40, 0x0FAAAA72 }, //Updated
    //{ 0xC8439C57, 0x638AE5B6 },
};

OldNewNid sceDisplay_driver_nid[] =
{
    { 0x63E22A26, 0xDC68E0EF }, //Updated
    { 0x5B5AEFAD, 0x452B3820 }, //Updated
    { 0x9E3C6DC6, 0xFF5A5D52 }, //Updated
    { 0x31C4BAA8, 0x43BA0974 }, //Updated
    { 0x7ED59BC4, 0xC7161CF7 }, //Updated
    { 0xBF79F646, 0xFAFF79B3 }, //Updated
    { 0xDBA6C4C4, 0x6ED9CDA2 },
    { 0xA83EF139, 0xF7774813 },
    { 0x210EAB3A, 0x2F06E30B }, //Updated
    { 0x773DD3A3, 0x7448FC95 },
    { 0xAE0E8972, 0x10B1710B },
    { 0x4D4E10EC, 0xBB8FD5C9 }, //Updated
    { 0x69B53541, 0x3F945436 }, //Updated
    { 0x66961521, 0x0AAF242A }, //Updated
    { 0x21038913, 0x800E01C6 }, //Updated
    { 0x92C8F8B7, 0x2DFD5B55 }, //Updated
    { 0xA544C486, 0xAAC50D73 }, //Updated
    { 0xF5EEEFEF, 0x6C42016A }, //Updated
    { 0x9C6EAAD7, 0x82DE8125 }, //Updated
    { 0xB4F378FA, 0xB550528B }, //Updated
    { 0xAC14F1FF, 0x4E7E51FC }, //Updated
    { 0xEEDA2E54, 0x64EE9BF2 }, //Updated
    { 0x289D82FE, 0xA231DB56 }, //Updated
    { 0x432D133F, 0xA20A245E }, //Updated
    { 0x681EE6A7, 0x2A1826A2 }, //Updated
    { 0x36CDFADE, 0xECFADEAB }, //Updated
    { 0x8EB9EC49, 0x770DF790 }, //Updated
    { 0x984C27E7, 0x2B4FF881 }, //Updated
    { 0x46F186C3, 0x0F82D90A }, //Updated
    { 0x946155FD, 0xA20A245E }, //Updated
    { 0x32B67781, 0x2A1826A2 }, //Updated
    { 0x820C6038, 0x85E81690 },
    { 0x776ADFDB, 0xFF5A5D52 }, //Updated
    { 0x1CB8CB47, 0x43BA0974 }, //Updated
    { 0x13AA96B7, 0xD41F8847 }, //Updated
    { 0xB685BA36, 0x2B4FF881 }, //Updated
    { 0x643F3841, 0xE4A61BA0 },
    { 0x4AB7497F, 0xA231DB56 }, //Updated
    { 0xE56B11BA, 0x64EE9BF2 }, //Updated
    { 0xE8466BC2, 0x82DE8125 }, //Updated
};

OldNewNid sceDve_driver_nid[] =
{
    { 0x0836B2B5, 0x9E03BCF9 }, //Updated
    { 0x17BC42E4, 0x5BC934E9 }, //Updated
    { 0xADE8C471, 0xE5EE11B3 }, //Updated
    { 0xD986F31B, 0x50005CD3 }, //Updated
    { 0xB7827F16, 0x46C595A3 }, //Updated
    { 0x34E9274D, 0xE926B3B8 }, //Updated
    { 0xE84E975E, 0xAB7574D1 }, //Updated
    { 0x0B85524C, 0x194FE107 }, //Updated
    { 0xA265B504, 0x024D7064 }, //Updated
    { 0xAE2A6570, 0x7C77EDA7 }, //Updated
    { 0xB2E4E437, 0x4210EB3C }, //Updated
    { 0xD8863512, 0xDB6BCBD6 }, //Updated
    { 0xDEB2F80C, 0xA1401BA2 }, //Updated
    { 0xA2D53F99, 0x46E070DD }, //Updated
    { 0xF0CF5A67, 0x0F748EAC }, //Updated
    { 0x93828323, 0x2F863B65 }, //Updated
    { 0xBF910381, 0xAA503020 }, //Updated
    { 0x36970008, 0x096FA2AE }, //Updated
    { 0x59E1B113, 0xF1175122 }, //Updated
    { 0xC9362C91, 0x9FC8CDA7 }, //Updated
    { 0x22D50DA7, 0xBD65CFAE }, //Updated
    //{ 0x292F15DA, 0xE35A4B28 },
};

OldNewNid sceGe_driver_nid[] =
{
    { 0xE0D68148, 0x862248FD }, //Updated
    { 0x71FCD1D6, 0x8AC047D1 }, //Updated
    { 0x9F2C2948, 0x6175E7FC }, //Updated
    { 0xB415364D, 0x87C1C34C }, //Updated
    { 0x51C8BB60, 0x8928D81B }, //Updated
    { 0xDC93CFEF, 0x2B37561E }, //Updated
    { 0x51D44C58, 0xE18D6B57 }, //Updated
    { 0x57C8945B, 0xA23C2482 }, //Updated
    { 0x5A0103E6, 0x56A5110E }, //Updated
    { 0x438A385A, 0x36585054 }, //Updated
    { 0x0BF608FB, 0x87A22519 }, //Updated
    { 0x9DA4A75F, 0x75CCB8EF }, //Updated
    { 0x8F185DF7, 0x9F724333 }, //Updated
    { 0x114E1745, 0xE3BCEAB6 }, //Updated
    { 0x5BAA5439, 0xD4D665C9 }, //Updated
    { 0xB77905EA, 0x8F1E3AF7 }, //Updated
    { 0x5FB86AB0, 0x7845ABFC }, //Updated
    { 0x03444EB4, 0x23E9F5FA }, //Updated
    { 0xB287BD61, 0xAC348640 }, //Updated
    { 0xB448EC0D, 0x3351EE04 }, //Updated
    { 0x4C06E472, 0x32A76BF7 }, //Updated
    { 0xA4FC06A4, 0xD57B9873 }, //Updated
    { 0xAEC21518, 0x3832B8F7 }, //Updated
    { 0x7B481502, 0xDABC7000 }, //Updated
    { 0x9ACFF59D, 0x002E0226 }, //Updated
    { 0x67B01D8E, 0x7FD1EBEF }, //Updated
    { 0xE66CB92E, 0x58935A8B }, //Updated
    { 0xAB49E76A, 0x7E2381D2 }, //Updated
    { 0x1C0D95A6, 0x362B73C5 }, //Updated
    { 0x05DB22CE, 0xFFD33EAC }, //Updated
    { 0xBAD6E1CA, 0xE08CA161 }, //Updated
    { 0xE47E40E4, 0x9919BBE3 }, //Updated
    { 0x1F6752AD, 0xF489E74B }, //Updated
    { 0xC576E897, 0xC774B373 }, //Updated
};

OldNewNid sceCtrl_driver_nid[] =
{
    { 0x1F4011E6, 0x262DD0DC }, //Updated
    { 0xDA6B76A1, 0xC44ED01B }, //Updated
    { 0x6A2774F3, 0xE4758982 }, //Updated
    { 0xB1D0E5CD, 0x655A18BE },
    { 0x0B588501, 0x5068A531 },
    { 0xB7CEAED4, 0x67B648BD },
    { 0xA7144800, 0x32999159 }, //Updated
    { 0x687660FA, 0xD821DF71 }, //Updated
    { 0x7CA723DC, 0xF3132A07 }, //Updated
    { 0x5E77BC8A, 0x063D8197 }, //Updated
    { 0x6841BE1A, 0xA2FF2213 }, //Updated
    { 0xC3F607F3, 0xA0798B29 }, //Updated
    { 0xC245B57B, 0x84793F3E }, //Updated
    { 0x02BAAD91, 0xA0390EE8 },
    { 0x3A622550, 0x3CA6922B }, //Updated
    { 0xC152080A, 0x2468E1F3 }, //Updated
    { 0x1F803938, 0xD073ECA4 }, //Updated
    { 0x60B81F86, 0x5E758582 }, //Updated
    { 0xA88E8D22, 0x0DCB5BD2 }, //Updated
    { 0x348D99D4, 0xB7D6332B }, //Updated
    { 0x9C521403, 0xA7D5A6BA }, //Updated
    { 0x02A10D22, 0xD8329216 }, //Updated
    { 0x5C56C779, 0x2037F8E7 },
    { 0xA68FD260, 0xF17D609C },
    { 0x252D3A8D, 0x5B2E5299 }, //Updated
    { 0xAF5960F3, 0xD2EC6240 }, //Updated
    { 0xCC70B61E, 0x2393D6F3 },
    { 0x3E65A0EA, 0x04A88056 }, //Updated
    { 0xE03956E9, 0x8FDE3DD5 }, //Updated
    { 0x28E71A16, 0x262DD0DC }, //Updated
    { 0x6D74BF08, 0xE4758982 }, //Updated
    { 0xC4AAD55F, 0x3CA6922B }, //Updated
    { 0x454455AC, 0xD073ECA4 }, //Updated
    { 0xFF847C31, 0xF54317C4 },
};

OldNewNid sceUmd_nid[] =
{
    { 0x659587F7, 0x004F4BE5 }, //Updated
    { 0xAE53DC2D, 0xB826BD59 }, //Updated
    { 0x230666E3, 0xF60013F8 }, //Updated
    { 0x319ED97C, 0x51046712 }, //Updated
    { 0x38503380, 0x31303428 }, //Updated
    { 0x086DDC0D, 0xB2AFFC75 }, //Updated
    { 0x4832ABF3, 0x4E92D55C }, //Updated
    { 0x4BA25F4A, 0xDB179672 }, //Updated
    { 0xBD2BDE07, 0x51C95C02 }, //Updated
    { 0xAEE7404D, 0x5083C012 }, //Updated
    { 0x46EBB729, 0xE70E8FFB }, //Updated
    { 0x6AF9B50A, 0x35B13E16 }, //Updated
    { 0x87533940, 0xB1641203 }, //Updated
    { 0xCBE9F02A, 0x70D9B731 }, //Updated
    { 0x3D0DECD5, 0x6664E727 }, //Updated
    { 0xD45D1FE6, 0x2D5CB292 }, //Updated
    { 0xD01B2DC6, 0xAB586818 }, //Updated
    { 0x3925CBD8, 0x4ECC8FC2 }, //Updated
    { 0x9B22AED7, 0x7E6182C7 }, //Updated
    { 0x71F81482, 0x1BA5BAFB }, //Updated
    { 0x7850F057, 0xDA980D66 }, //Updated
    { 0x27A764A1, 0x569DEE7C }, //Updated
    { 0xF8352373, 0x243C95B5 }, //Updated
    { 0x5469DC37, 0xFACF102F }, //Updated
    { 0x2D81508D, 0x6CA782BF }, //Updated
    { 0x56202973, 0x6592E954 }, //Updated
    { 0x4A9E5E29, 0x74145046 }, //Updated
    { 0x075F1E0B, 0x63E209AC }, //Updated
    { 0x340B7686, 0x9F53CFA1 }, //Updated
    { 0xEB56097E, 0x69801EEC }, //Updated
    { 0x6A41ED25, 0xE9101A0E }, //Updated
    { 0x4C952ACF, 0x259BDD2E }, //Updated
    { 0xF2D0EDFB, 0xE70E8FFB }, //Updated
};

OldNewNid sceHprm_driver_nid[] =
{
    { 0xC7154136, 0xE611E89B }, //Updated
    { 0xFD7DE6CD, 0xBF4C183C }, //Updated
    { 0x8EC787E0, 0x0CB055CC }, //Updated
    { 0xBAD0828E, 0x732EC325 }, //Updated
    { 0x4D1E622C, 0x1F631BD7 }, //Updated
    { 0x2BCEC83E, 0x00CFE490 }, //Updated
    { 0x40D2F9F0, 0x5FC5E53B }, //Updated
    { 0x9C1D9ADB, 0xDA01152D }, //Updated
    { 0xB6B6786B, 0x61650073 }, //Updated
    { 0x7B038374, 0x34906CFF }, //Updated
    { 0x21E8AFD5, 0xEAE19005 }, //Updated
    { 0x6BC7BEE9, 0xCDACC031 }, //Updated
    { 0xC0FE0FAD, 0xC61FC867 }, //Updated
    { 0x7B1A14B8, 0x2F028F97 }, //Updated
    { 0xF04591FA, 0x5CE3A57B }, //Updated
    { 0x971AE8FB, 0xEC254B64 }, //Updated
    { 0x71B5FB67, 0x8A898B38 }, //Updated
    { 0x7E69EDA4, 0x2E49469C }, //Updated
    { 0x208DB1BD, 0x4C9BEDA4 }, //Updated
    { 0x219C58F1, 0xE0F76A26 }, //Updated
    { 0xC1777D84, 0x62CDFB12 }, //Updated
    { 0x1528D408, 0x61650073 }, //Updated
    { 0xD22913DB, 0x1EECCA1A }, //Updated
    { 0x133DE8FA, 0x74B54AEA }, //Updated
};

OldNewNid scePower_driver_nid[] =
{
    { 0x04B7766E, 0x1A41E0ED }, //Updated
    { 0xDFA8BAF8, 0x5EE66C30 },
    { 0xA9D22232, 0xDB086E2B }, //Updated
    { 0xBAFA3DF0, 0x75E2A155 }, //Updated
    { 0x442BFBAC, 0x4084E678 }, //Updated
    { 0xD66EF08D, 0x9CDB22B5 }, //Updated
    { 0x6D2CA84B, 0xA8909AE1 }, //Updated
    { 0x23BB0A60, 0x5D311801 }, //Updated
    { 0x23C31FFE, 0xE2AFADF3 },
    { 0xFA97A599, 0x66335AEB },
    { 0xB3EDD801, 0x3B969585 },
    { 0x79DB9421, 0x86B475A4 }, //Updated
    { 0x2B7C7CF4, 0x47F4E1A8 }, //Updated
    { 0xAC32C9CC, 0xC9885394 }, //Updated
    { 0x2875994B, 0x8AFD31BC }, //Updated
    { 0x0442D852, 0x599A2901 }, //Updated
    { 0x7F30B3B1, 0x69513373 }, //Updated
    { 0x972CE941, 0x21361196 }, //Updated
    { 0x843FBF43, 0x37DCC2DA }, //Updated
    { 0xB8D7B3FB, 0xC5371DAD }, //Updated
    { 0xE0B7A95D, 0x08354E58 }, //Updated
    { 0x166922EC, 0xA247240B }, //Updated
    { 0xDD3D4DAC, 0xCA1B6E91 }, //Updated
    { 0x733F973B, 0xF52F66EB }, //Updated
    { 0x90285886, 0xC2B7CD0C }, //Updated
    { 0xB4432BC8, 0x5D9E954F }, //Updated
    { 0x8EFB3FA2, 0xB3C30947 }, //Updated
    { 0x862AE1A6, 0xDC73B503 }, //Updated
    { 0x27F3292C, 0x79CC68FC }, //Updated
    { 0xD3075926, 0x279492B3 }, //Updated
    { 0x23436A4A, 0x4AA479BE }, //Updated
    { 0xC71EE866, 0x207119B3 }, //Updated
    { 0x28E12023, 0xE66978D7 }, //Updated
    { 0xCB49F5CE, 0xA73D777D }, //Updated
    { 0xD7B9C925, 0x2D5A880D }, //Updated
    { 0x2B51FE2F, 0x2303E6AE },
    { 0xD6D016EF, 0x534D471F }, //Updated
    { 0x0CD21B1F, 0x9E08030B }, //Updated
    { 0x165CE085, 0x92030113 }, //Updated
    { 0xCA3D34C1, 0xD80E403B }, //Updated
    { 0x7FA406DD, 0xE5C40F85 }, //Updated
    { 0x0074EF9B, 0x0633D9DC }, //Updated
    { 0xF535D928, 0x9A27EFA6 }, //Updated
    { 0xC23AC778, 0xA4ABE2C5 }, //Updated
    { 0x57A098B4, 0x9E1FB9FE }, //Updated
    { 0x55D2D789, 0x071F03B8 }, //Updated
    { 0xDD27F119, 0x45E2AEB9 }, //Updated
    { 0x75F91FE4, 0xE4C917A5 }, //Updated
    { 0x06C83A4F, 0x6DE6166A }, //Updated
    { 0x4E759486, 0x37C9C3FE }, //Updated
    { 0x53C1255D, 0xDDBB64D9 }, //Updated
    { 0x8762BCE6, 0x5D3CE741 }, //Updated
    { 0xCAE2A4CA, 0x7E30F280 }, //Updated
    { 0xD24E6BEB, 0xA30B558A }, //Updated
    { 0x35B7662E, 0x2F67557D }, //Updated
    { 0xF9B4DEA1, 0xE3A5CA86 }, //Updated
    { 0xF06B96D4, 0x5996754F }, //Updated
    { 0xB1A52C83, 0x4CAE06EF }, //Updated
    { 0x478FE6F5, 0xBF5BA7FC }, //Updated
    { 0xBD681969, 0x78834264 },
    { 0x9BADB3EB, 0x279FD567 }, //Updated
    { 0x34F9C463, 0xBA93F79B }, //Updated
    { 0xEA382A27, 0x666E6BE3 }, //Updated
    { 0x3234844A, 0x284A0F59 }, //Updated
    { 0x94F5A53F, 0xB6782EAE }, //Updated
    { 0xE8E4E204, 0x9E77DDBA }, //Updated
    { 0xB999184C, 0x8BDEC501 }, //Updated
    { 0x87440F5E, 0x7F480684 }, //Updated
    { 0x0AFD0D8B, 0xBC8823E8 }, //Updated
    { 0x1E490401, 0x5202A826 }, //Updated
    { 0xC3C33306, 0x756261FC }, //Updated
    { 0xFD18A0FF, 0x6E7E0056 }, //Updated
    { 0x2085D15D, 0xE5F8596E }, //Updated
    { 0x483CE86B, 0x3C7B0B84 }, //Updated
    { 0xA4D02055, 0x5BB0D018 }, //Updated
    { 0x3951AF53, 0x39274F61 }, //Updated
    { 0xEFD3C963, 0xE59EF335 }, //Updated
    { 0xEDC13FE5, 0xB361215A }, //Updated
    { 0x78A1A796, 0x9E09D19B }, //Updated
    /*{ 0x9B1A9C5F, 0x47CDDC1A },
    { 0xE65F00BD, 0x80A2AAD4 },
    { 0x9C40E184, 0xA40EC0F7 },
    { 0x1688935C, 0x78834264 },*/
    { 0xFEE03A2F, 0xFDB5BFE9 }, //0xB1A52C83
};

OldNewNid sceImpose_driver_nid[] =
{
    { 0x9C8C6C81, 0x01EF0650 }, //Updated
    { 0x36AA6E91, 0xEC3F0727 }, //Updated
    { 0x24FD7BCF, 0x7C972622 }, //Updated
    { 0x8C943191, 0x4D849B71 }, //Updated
    { 0xC7E36CC7, 0x3745B423 }, //Updated
    { 0x5595A71A, 0x5D93BBE4 }, //Updated
    { 0x0F341BE4, 0x67544934 }, //Updated
    { 0x72189C48, 0xD8CCF6D2 }, //Updated
    { 0xE0887BC8, 0xCFA708BD }, //Updated
    { 0x381BD9E7, 0xFD250093 }, //Updated
    { 0x9DBCE0C4, 0x6A35E462 }, //Updated
    { 0x967F6D4A, 0x9954A241 }, //Updated
    { 0x8F6E3518, 0xC54F98F6 }, //Updated
    { 0xFF1A2F07, 0xBFB8473E }, //Updated
    { 0x7084E72C, 0x90AB6874 }, //Updated
    { 0x1B6E3400, 0xDC6B1382 }, //Updated
    { 0xB415FC59, 0x55864BD7 }, //Updated
    { 0x531C9778, 0xC94AC8E2 }, //Updated
    { 0x810FB7FB, 0xC5EA0BAC }, //Updated
    { 0x116CFF64, 0x2700B882 }, //Updated
    { 0x116DDED6, 0x25011AAB }, //Updated
    { 0xBDBC42A6, 0x76D7E4D4 }, //Updated
    { 0x1AEED8FE, 0x39B67435 }, //Updated
    { 0x86924032, 0x80B0A780 }, //Updated
};

OldNewNid sceRtc_driver_nid[] =
{
    { 0x9763C138, 0x8FD3886D }, //Updated
    { 0x7D1FBED3, 0x68AED59A }, //Updated
    { 0xC2DDBEB5, 0x19C3C426 }, //Updated
    { 0x81FCDA34, 0x46C695AA }, //Updated
    { 0xFB3B18CD, 0xE1F7B409 }, //Updated
    { 0x203CEB0D, 0xC55A5A0C }, //Updated
    { 0x62685E98, 0x7D70D63F }, //Updated
    { 0x759937C5, 0xCFBE4A68 }, //Updated
    { 0x6A676D2D, 0x49FF9A51 }, //Updated
    { 0xE7C27D1B, 0xA0B3BF0F }, //Updated
    { 0x34885E0D, 0x2F20DAF0 }, //Updated
    { 0x779242A2, 0x6A41FE5E }, //Updated
    { 0x42307A17, 0x2510903A }, //Updated
    { 0x05EF322C, 0xA99453A4 }, //Updated
    { 0x36075567, 0xE9B6C08A }, //Updated
    { 0xCF561893, 0x120ED794 }, //Updated
    { 0xE1C93E47, 0x4F9F0E2C }, //Updated
    { 0x27C4594C, 0x7B463901 }, //Updated
    { 0x7ED29E40, 0x43F38ED8 }, //Updated
    { 0xDBF74F1B, 0xEB013962 }, //Updated
    { 0x42842C77, 0x76C60BEB }, //Updated
    { 0x57726BC1, 0x6F2FC44B }, //Updated
    { 0xF006F264, 0xB9B1CD57 }, //Updated
    { 0x7ACE4C04, 0x36CB9E04 }, //Updated
    { 0x1909C99B, 0xCD653A7E }, //Updated
    { 0x3A807CC8, 0x4A317519 }, //Updated
    { 0x26D25A5D, 0x3BFB5E74 }, //Updated
    { 0x26D7A24A, 0x63EF93F0 }, //Updated
    { 0xE51B4B7A, 0x258213AF }, //Updated
    { 0xCF3A2CA8, 0xC4A12BFC }, //Updated
    { 0x9ED0AE87, 0xE2BE9595 }, //Updated
    { 0xDFBC5F16, 0xFC555073 }, //Updated
    { 0x28E1E988, 0xDDC10EEE }, //Updated
    { 0xC663B3B9, 0x108E9C68 }, //Updated
    { 0x0498FB3C, 0x05487F6A }, //Updated
    { 0x7DE6711B, 0xB1E3C114 }, //Updated
    { 0x27F98543, 0x5D6735B0 }, //Updated
    { 0xF0B5571C, 0xB859041B }, //Updated
    { 0xD24DF719, 0xF2FCB0F3 }, //Updated
    { 0xC499AF2F, 0x2D37DC1E }, //Updated
    { 0xE6605BCA, 0xC59704E1 }, //Updated
};

OldNewNid sceReg_driver_nid[] =
{
    { 0x98279CF1, 0x10808BB5 }, //Updated
    { 0x9B25EDF1, 0x5B06A7B9 }, //Updated
    { 0x92E41280, 0x873EB4E1 }, //Updated
    { 0xFA8A5739, 0xF3300EBF }, //Updated
    { 0xDEDA92BF, 0x632E987D }, //Updated
    { 0x1D8A762E, 0x8A0F5133 }, //Updated
    { 0x4CA16893, 0xAF9FBE8E }, //Updated
    { 0xBE8C1263, 0x675482AD }, //Updated
    { 0x835ECE6F, 0x3D3A1014 }, //Updated
    { 0x57641A81, 0x762C35DC }, //Updated
    { 0x17768E14, 0xDC7EF81C }, //Updated
    { 0xD4475AA8, 0x400BB753 }, //Updated
    { 0xC5768D02, 0xB4E27416 }, //Updated
    { 0x28A8E98A, 0x08BEB24C }, //Updated
    { 0x30BE0259, 0x4D81184D }, //Updated
    { 0x3615BC87, 0x89DBFC66 }, //Updated
    { 0x2C0DB9DD, 0xF8E1F5A1 }, //Updated
    { 0x2D211135, 0x73B8B70E }, //Updated
    { 0x39461B4D, 0x31F9DB91 }, //Updated
    { 0x0D69BF40, 0x0404652C }, //Updated
    { 0x0CAE832B, 0x21928F15 }, //Updated
};

OldNewNid memlmd_nid[] =
{
    { 0x323366CA, 0x2E208358 }, //Updated
    { 0x1570BAB4, 0x8450109F }, //Updated
    { 0x7CF1CD3E, 0xCA560AA6 }, //Updated
};

OldNewNid sceMesgLed_driver_nid[] =
{
    { 0xDFF0F308, 0x5D799BBF }, //Updated
};

OldNewNid sceClockgen_driver_nid[] =
{
    { 0x4EB657D5, 0xACC30ECE }, //Updated
};

OldNewNid sceCodec_driver_nid[] =
{
    { 0x20C61103, 0xBCE58DC4 }, //Updated
};

typedef struct
{
    char *libname;
	OldNewNid *nid;
	int n_nid;
} NidTable;

NidTable nid_table_620[] =
{
    { "SysMemForKernel", SysMemForKernel_nid, N_NID(SysMemForKernel_nid) },
    { "KDebugForKernel", KDebugForKernel_nid, N_NID(KDebugForKernel_nid) },
    { "LoadCoreForKernel", LoadCoreForKernel_nid, N_NID(LoadCoreForKernel_nid) },
    { "ExceptionManagerForKernel", ExceptionManagerForKernel_nid, N_NID(ExceptionManagerForKernel_nid) },
    { "InterruptManagerForKernel", InterruptManagerForKernel_nid, N_NID(InterruptManagerForKernel_nid) },
    { "IoFileMgrForKernel", IoFileMgrForKernel_nid, N_NID(IoFileMgrForKernel_nid) },
    { "ModuleMgrForKernel", ModuleMgrForKernel_nid, N_NID(ModuleMgrForKernel_nid) },
    { "LoadExecForKernel", LoadExecForKernel_nid, N_NID(LoadExecForKernel_nid) },
    { "sceDdr_driver", sceDdr_driver_nid, N_NID(sceDdr_driver_nid) },
    { "sceDmacplus_driver", sceDmacplus_driver_nid, N_NID(sceDmacplus_driver_nid) },
    { "sceGpio_driver", sceGpio_driver_nid, N_NID(sceGpio_driver_nid) },
    { "sceSysreg_driver", sceSysreg_driver_nid, N_NID(sceSysreg_driver_nid) },
    { "sceSyscon_driver", sceSyscon_driver_nid, N_NID(sceSyscon_driver_nid) },
    { "sceDisplay_driver", sceDisplay_driver_nid, N_NID(sceDisplay_driver_nid) },
    { "sceDve_driver", sceDve_driver_nid, N_NID(sceDve_driver_nid) },
    { "sceGe_driver", sceGe_driver_nid, N_NID(sceGe_driver_nid) },
    { "sceCtrl_driver", sceCtrl_driver_nid, N_NID(sceCtrl_driver_nid) },
    { "sceUmd", sceUmd_nid, N_NID(sceUmd_nid) },
    { "sceHprm_driver", sceHprm_driver_nid, N_NID(sceHprm_driver_nid) },
    { "scePower_driver", scePower_driver_nid, N_NID(scePower_driver_nid) },
    { "sceImpose_driver", sceImpose_driver_nid, N_NID(sceImpose_driver_nid) },
    { "sceRtc_driver", sceRtc_driver_nid, N_NID(sceRtc_driver_nid) },
    { "sceReg_driver", sceReg_driver_nid, N_NID(sceReg_driver_nid) },
    { "memlmd", memlmd_nid, N_NID(memlmd_nid) },
    { "sceMesgLed_driver", sceMesgLed_driver_nid, N_NID(sceMesgLed_driver_nid) },
    { "sceClockgen_driver", sceClockgen_driver_nid, N_NID(sceClockgen_driver_nid) },
    { "sceCodec_driver", sceCodec_driver_nid, N_NID(sceCodec_driver_nid) },
};

#define NIDS_N (sizeof(nid_table_620) / sizeof(NidTable))

#endif