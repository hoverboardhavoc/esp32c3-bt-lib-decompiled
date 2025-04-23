/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_res_list_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
r_lld_res_list_add(void *param_1,void *param_2,void *param_3,uint param_4,int param_5,int param_6)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  void *pvVar7;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  local_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  iVar3 = memcmp(param_3,&local_40,0x10);
  iVar4 = memcmp(param_2,&local_40,0x10);
  iVar5 = r_lld_ral_search(param_1,param_4);
  if (iVar5 == 10) {
    uVar2 = 0;
    do {
      iVar5 = r_emi_get_mem_addr_by_offset(0xc60);
      if (-1 < *(short *)(uVar2 * 0x34 + iVar5)) {
        iVar5 = (uVar2 & 0xff) * 0x34;
        pvVar7 = (void *)r_emi_get_mem_addr_by_offset(iVar5 + 0xc78);
        memcpy(pvVar7,param_1,6);
        if (iVar3 != 0) {
          pvVar7 = (void *)r_emi_get_mem_addr_by_offset(iVar5 + 0xc7e);
          memcpy(pvVar7,param_3,0x10);
        }
        if (iVar4 != 0) {
          pvVar7 = (void *)r_emi_get_mem_addr_by_offset(iVar5 + 0xc62);
          memcpy(pvVar7,param_2,0x10);
        }
        bVar1 = privacy_en;
        if (1 < param_4) {
          r_assert_err(0,"lld.c",0x66);
        }
        iVar5 = r_emi_get_mem_addr_by_offset(0xc60);
        *(ushort *)(uVar2 * 0x34 + iVar5) =
             (ushort)(iVar4 != 0) << 1 | (ushort)bVar1 << 0xb | (ushort)(param_6 << 0xd) |
             (ushort)(param_5 << 0xe) | (ushort)param_4 | (ushort)(iVar3 != 0) << 6 |
             (ushort)(iVar3 != 0) << 5 | (ushort)(iVar4 != 0) << 2 | 0x8000;
        return 0;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 != 10);
    uVar6 = 7;
  }
  else {
    uVar6 = 0x12;
  }
  return uVar6;
}

