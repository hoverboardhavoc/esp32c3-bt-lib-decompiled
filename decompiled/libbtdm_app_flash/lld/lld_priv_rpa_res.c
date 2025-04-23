/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld.o -> lld_priv_rpa_res
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 lld_priv_rpa_res(void *param_1,void *param_2,short *param_3)

{
  short sVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  void *__s1;
  void *__s2;
  ushort uVar5;
  uint uVar6;
  char *pcVar7;
  
  if (param_3 == (short *)0x0) {
    return 0;
  }
  if (param_1 == (void *)0x0) {
    if (param_2 == (void *)0x0) {
      return 0;
    }
  }
  else {
    if ((*(byte *)((int)param_1 + 5) & 0xc0) != 0x40) {
      return 0;
    }
    if (param_2 == (void *)0x0) goto _L130;
  }
  if ((*(byte *)((int)param_2 + 5) & 0xc0) != 0x40) {
    return 0;
  }
_L130:
  pcVar7 = &lld_rpa_res_list;
  bVar2 = param_1 == (void *)0x0;
  bVar3 = param_2 == (void *)0x0;
  uVar5 = 0;
  do {
    if (*pcVar7 != '\0') {
      if (param_1 != (void *)0x0) {
        iVar4 = memcmp(param_1,pcVar7 + 1,6);
        bVar2 = (bool)(bVar2 | iVar4 == 0);
      }
      if (param_2 != (void *)0x0) {
        iVar4 = memcmp(param_2,pcVar7 + 7,6);
        bVar3 = (bool)(bVar3 | iVar4 == 0);
      }
      if ((bVar2) && (bVar3)) {
        *param_3 = uVar5 * 0x34 + 0xc60;
        return 1;
      }
    }
    uVar5 = uVar5 + 1 & 0xff;
    pcVar7 = pcVar7 + 0xd;
  } while (uVar5 != 10);
  uVar6 = 0;
  do {
    iVar4 = r_emi_get_mem_addr_by_offset(0xc60);
    if ((*(short *)(iVar4 + uVar6 * 0x34) < 0) &&
       ((param_1 == (void *)0x0 || (iVar4 = lld_peer_rpa_res(param_1,uVar6 & 0xff), iVar4 != 0)))) {
      if (param_2 == (void *)0x0) goto _L139;
      sVar1 = *param_3;
      iVar4 = r_emi_get_mem_addr_by_offset(0xc60);
      if ((*(ushort *)(iVar4 + uVar6 * 0x34) & 0x20) != 0) {
        __s1 = (void *)r_emi_get_mem_addr_by_offset(uVar6 * 0x34 + 0xc7e & 0xffff);
        if ((ushort)(sVar1 - 0xc60U) < 0x209) {
          __s2 = (void *)r_emi_get_mem_addr_by_offset(sVar1 + 0x1e);
          iVar4 = memcmp(__s1,__s2,0x10);
          if (iVar4 == 0) {
_L139:
            *param_3 = ((ushort)uVar6 & 0xff) * 0x34 + 0xc60;
            if (param_1 != (void *)0x0) {
              memcpy(&DAT_00012fbd + uVar6 * 0xd,param_1,6);
            }
            if (param_2 != (void *)0x0) {
              memcpy(&DAT_00012fc3 + uVar6 * 0xd,param_2,6);
            }
            (&lld_rpa_res_list)[uVar6 * 0xd] = 1;
            return 1;
          }
        }
        else {
          iVar4 = lld_rpa_res(param_2);
          if (iVar4 != 0) goto _L139;
        }
      }
    }
    uVar6 = uVar6 + 1;
    if (uVar6 == 10) {
      return 0;
    }
  } while( true );
}

