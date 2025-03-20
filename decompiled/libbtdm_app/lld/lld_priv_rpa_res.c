/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
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
  void *__s1;
  void *__s2;
  uint uVar7;
  uint uVar8;
  ushort uVar9;
  char *pcVar10;
  char cVar11;
  char cVar12;
  
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
    if (param_2 == (void *)0x0) goto _L201;
  }
  if ((*(byte *)((int)param_2 + 5) & 0xc0) != 0x40) {
    return '\0';
  }
_L201:
  pcVar10 = &lld_rpa_res_list;
  cVar11 = param_1 == (void *)0x0;
  cVar12 = param_2 == (void *)0x0;
  uVar9 = 0;
  do {
    cVar1 = *pcVar10;
    if (cVar1 != '\0') {
      if ((param_1 == (void *)0x0) || (iVar6 = memcmp(param_1,pcVar10 + 1,6), iVar6 != 0)) {
        if (param_2 != (void *)0x0) goto _L221;
_L205:
        cVar4 = cVar12;
        cVar5 = cVar1;
        cVar3 = cVar12;
        if (cVar11 == '\0') goto _L202;
      }
      else {
        cVar11 = cVar1;
        cVar4 = cVar12;
        cVar5 = cVar1;
        cVar3 = cVar12;
        if (param_2 != (void *)0x0) {
_L221:
          iVar6 = memcmp(param_2,pcVar10 + 7,6);
          cVar4 = cVar1;
          cVar5 = cVar11;
          cVar3 = cVar11;
          if (iVar6 != 0) goto _L205;
        }
      }
      cVar11 = cVar5;
      cVar12 = cVar4;
      if (cVar3 != '\0') {
        *param_3 = uVar9 * 0x34 + 0xc60;
        return cVar1;
      }
    }
_L202:
    uVar9 = uVar9 + 1 & 0xff;
    pcVar10 = pcVar10 + 0xd;
  } while (uVar9 != 10);
  uVar8 = 0;
  do {
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
    if ((*(short *)(iVar6 + uVar8 * 0x34) < 0) &&
       ((param_1 == (void *)0x0 || (iVar6 = lld_peer_rpa_res(param_1,uVar8 & 0xff), iVar6 != 0)))) {
      if (param_2 == (void *)0x0) {
_L212:
        *param_3 = (short)(uVar8 & 0xff) * 0x34 + 0xc60;
        if (param_1 != (void *)0x0) {
          memcpy(&DAT_00013339 + uVar8 * 0xd,param_1,6);
        }
        if (param_2 != (void *)0x0) {
          memcpy(&DAT_0001333f + uVar8 * 0xd,param_2,6);
        }
        (&lld_rpa_res_list)[uVar8 * 0xd] = 1;
        return '\x01';
      }
      sVar2 = *param_3;
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
      if ((*(ushort *)(iVar6 + uVar8 * 0x34) & 0x20) != 0) {
        __s1 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                 (uVar8 * 0x34 + 0xc7e & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
        if ((ushort)(sVar2 - 0xc60U) < 0x209) {
          __s2 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                   (sVar2 + 0x1e,*(code **)(_r_plf_funcs_p + 0xbc));
          iVar6 = memcmp(__s1,__s2,0x10);
          uVar7 = (uint)(iVar6 == 0);
        }
        else {
          uVar7 = lld_rpa_res(param_2);
        }
        if (uVar7 != 0) goto _L212;
      }
    }
    uVar8 = uVar8 + 1;
    if (uVar8 == 10) {
      return '\0';
    }
  } while( true );
}

