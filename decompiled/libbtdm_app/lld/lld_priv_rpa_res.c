/*
 * Last changed at upstream commit 27af69ccbb02f3b820436f47eaa0b1cd544edfbc
 * https://github.com/espressif/esp32c3-bt-lib/commit/27af69ccbb02f3b820436f47eaa0b1cd544edfbc
 * Upstream date: 2023-09-26 16:09:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(c8aa206)
 * Source: libbtdm_app -> lld.o -> lld_priv_rpa_res
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char lld_priv_rpa_res(void *param_1,void *param_2,short *param_3)

{
  char cVar1;
  short sVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  void *__s1;
  void *__s2;
  uint uVar8;
  ushort uVar9;
  char *pcVar10;
  char cVar11;
  int iVar12;
  char cVar13;
  
  if (param_3 == (short *)0x0) {
    return '\0';
  }
  if (param_1 == (void *)0x0) {
    if (param_2 == (void *)0x0) {
      return '\0';
    }
  }
  else {
    if ((*(byte *)((int)param_1 + 5) & 0xc0) != 0x40) {
      return '\0';
    }
    if (param_2 == (void *)0x0) goto _L171;
  }
  if ((*(byte *)((int)param_2 + 5) & 0xc0) != 0x40) {
    return '\0';
  }
_L171:
  pcVar10 = &lld_rpa_res_list;
  cVar11 = param_1 == (void *)0x0;
  cVar13 = param_2 == (void *)0x0;
  uVar9 = 0;
  do {
    cVar1 = *pcVar10;
    if (cVar1 != '\0') {
      if ((param_1 == (void *)0x0) || (iVar6 = memcmp(param_1,pcVar10 + 1,6), iVar6 != 0)) {
        if (param_2 != (void *)0x0) goto _L191;
_L175:
        cVar4 = cVar13;
        cVar5 = cVar1;
        cVar3 = cVar13;
        if (cVar11 == '\0') goto _L172;
      }
      else {
        cVar11 = cVar1;
        cVar4 = cVar13;
        cVar5 = cVar1;
        cVar3 = cVar13;
        if (param_2 != (void *)0x0) {
_L191:
          iVar6 = memcmp(param_2,pcVar10 + 7,6);
          cVar4 = cVar1;
          cVar5 = cVar11;
          cVar3 = cVar11;
          if (iVar6 != 0) goto _L175;
        }
      }
      cVar11 = cVar5;
      cVar13 = cVar4;
      if (cVar3 != '\0') {
        *param_3 = uVar9 * 0x34 + 0xc60;
        return cVar1;
      }
    }
_L172:
    uVar9 = uVar9 + 1 & 0xff;
    pcVar10 = pcVar10 + 0xd;
  } while (uVar9 != 10);
  iVar6 = 0;
  do {
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar12 = iVar6 * 0x34;
    if (*(short *)(iVar7 + iVar12) < 0) {
      if (param_1 == (void *)0x0) {
_L185:
        if (param_2 == (void *)0x0) {
_L182:
          *param_3 = ((ushort)iVar6 & 0xff) * 0x34 + 0xc60;
          if (param_1 != (void *)0x0) {
            memcpy(&DAT_00010f41 + iVar6 * 0xd,param_1,6);
          }
          if (param_2 != (void *)0x0) {
            memcpy(&DAT_00010f47 + iVar6 * 0xd,param_2,6);
          }
          (&lld_rpa_res_list)[iVar6 * 0xd] = 1;
          return '\x01';
        }
        sVar2 = *param_3;
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
        if ((*(ushort *)(iVar7 + iVar12) & 0x20) != 0) {
          __s1 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                   (iVar6 * 0x34 + 0xc7eU & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc)
                                   );
          if ((ushort)(sVar2 - 0xc60U) < 0x209) {
            __s2 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                     (sVar2 + 0x1e,*(code **)(_r_plf_funcs_p + 0xbc));
            iVar7 = memcmp(__s1,__s2,0x10);
            uVar8 = (uint)(iVar7 == 0);
          }
          else {
            uVar8 = lld_rpa_res(param_2);
          }
          if (uVar8 != 0) goto _L182;
        }
      }
      else {
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
        if ((*(ushort *)(iVar7 + iVar12) & 2) != 0) {
          (**(code **)(_r_plf_funcs_p + 0xbc))
                    (iVar6 * 0x34 + 0xc62U & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
          iVar7 = lld_rpa_res(param_1);
          if (iVar7 != 0) goto _L185;
        }
      }
    }
    iVar6 = iVar6 + 1;
    if (iVar6 == 10) {
      return '\0';
    }
  } while( true );
}

