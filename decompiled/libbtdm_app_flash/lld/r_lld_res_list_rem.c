/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_res_list_rem
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_res_list_rem(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  void *pvVar8;
  
  iVar5 = r_lld_ral_search();
  if (iVar5 == 10) {
    return 2;
  }
  iVar4 = iVar5 * 0x34;
  iVar6 = r_emi_get_mem_addr_by_offset(0xc60);
  if ((((int)((uint)*(ushort *)(iVar6 + iVar4) << 0x12) < 0) &&
      (iVar6 = r_emi_get_mem_addr_by_offset(0xc60), (*(ushort *)(iVar6 + iVar4) >> 1 & 1) != 0)) &&
     (iVar6 = lld_wl_search(param_1,param_2), iVar6 != 0xc)) {
    pbVar2 = (byte *)(&lld_wl_res_list)[iVar6];
    if (pbVar2 == (byte *)0x0) {
      pbVar2 = (byte *)(**(code **)(_r_osi_funcs_p + 0x74))(0x17,*(code **)(_r_osi_funcs_p + 0x74));
      (&lld_wl_res_list)[iVar6] = pbVar2;
      if (pbVar2 == (byte *)0x0) goto _L267;
    }
    iVar7 = r_emi_get_mem_addr_by_offset(0xc60);
    *pbVar2 = (byte)*(undefined2 *)(iVar7 + iVar4) & 1;
    iVar7 = (&lld_wl_res_list)[iVar6];
    uVar3 = (uint)(iVar5 * 0x340000) >> 0x10;
    pvVar8 = (void *)r_emi_get_mem_addr_by_offset(uVar3 + 0xc78 & 0xffff);
    memcpy((void *)(iVar7 + 1),pvVar8,6);
    iVar6 = (&lld_wl_res_list)[iVar6];
    pvVar8 = (void *)r_emi_get_mem_addr_by_offset(uVar3 + 0xc62 & 0xffff);
    memcpy((void *)(iVar6 + 7),pvVar8,0x10);
  }
_L267:
  iVar6 = r_emi_get_mem_addr_by_offset(0xc60);
  uVar1 = *(ushort *)(iVar6 + iVar4);
  iVar6 = r_emi_get_mem_addr_by_offset(0xc60);
  *(ushort *)(iVar4 + iVar6) = (ushort)(((uint)uVar1 << 0x11) >> 0x11);
  memset(&lld_rpa_res_list + iVar5 * 0xd,0,0xd);
  return 0;
}

