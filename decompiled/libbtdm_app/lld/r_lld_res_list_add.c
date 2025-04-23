/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld.o -> r_lld_res_list_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
r_lld_res_list_add(void *param_1,void *param_2,void *param_3,uint param_4,int param_5,int param_6)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  void *pvVar7;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  
  local_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  iVar2 = memcmp(param_3,&local_50,0x10);
  iVar3 = memcmp(param_2,&local_50,0x10);
  uVar4 = (**(code **)(_r_ip_funcs_p + 0x260))(param_1,param_4,*(code **)(_r_ip_funcs_p + 0x260));
  if (uVar4 < 10) {
    uVar6 = 0x12;
  }
  else {
    uVar4 = 0;
    do {
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
      if (-1 < *(short *)(uVar4 * 0x34 + iVar5)) {
        iVar5 = (uVar4 & 0xff) * 0x34;
        pvVar7 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                   (iVar5 + 0xc78,*(code **)(_r_plf_funcs_p + 0xbc));
        memcpy(pvVar7,param_1,6);
        if (iVar2 != 0) {
          pvVar7 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                     (iVar5 + 0xc7e,*(code **)(_r_plf_funcs_p + 0xbc));
          memcpy(pvVar7,param_3,0x10);
        }
        if (iVar3 != 0) {
          pvVar7 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                     (iVar5 + 0xc62,*(code **)(_r_plf_funcs_p + 0xbc));
          memcpy(pvVar7,param_2,0x10);
        }
        bVar1 = privacy_en;
        if (1 < param_4) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld.c",0x66,*(code **)(_r_plf_funcs_p + 8));
        }
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(uVar4 * 0x34 + iVar5) =
             (ushort)(iVar3 != 0) << 1 | (ushort)bVar1 << 0xb | (ushort)(param_6 << 0xd) |
             (ushort)(param_5 << 0xe) | (ushort)param_4 | (ushort)(iVar2 != 0) << 6 |
             (ushort)(iVar2 != 0) << 5 | (ushort)(iVar3 != 0) << 2 | 0x8000;
        return 0;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 != 10);
    uVar6 = 7;
  }
  return uVar6;
}

