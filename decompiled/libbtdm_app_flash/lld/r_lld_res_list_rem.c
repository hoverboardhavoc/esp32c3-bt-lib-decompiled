/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  void *pvVar7;
  undefined4 uVar8;
  int *piVar9;
  
  uVar4 = r_lld_ral_search();
  if (uVar4 < 10) {
    iVar3 = uVar4 * 0x34;
    iVar5 = r_emi_get_mem_addr_by_offset(0xc60);
    if ((*(ushort *)(iVar5 + iVar3) >> 0xd & 1) != 0) {
      iVar5 = r_emi_get_mem_addr_by_offset(0xc60);
      if (((*(ushort *)(iVar5 + iVar3) >> 1 & 1) != 0) &&
         (uVar6 = lld_wl_search(param_1,param_2), uVar6 < 0xc)) {
        if ((&lld_wl_res_list)[uVar6] == 0) {
          iVar5 = (**(code **)(_r_osi_funcs_p + 0x74))(0x17,*(code **)(_r_osi_funcs_p + 0x74));
          (&lld_wl_res_list)[uVar6] = iVar5;
        }
        piVar9 = &lld_wl_res_list + uVar6;
        pbVar2 = (byte *)*piVar9;
        if (pbVar2 != (byte *)0x0) {
          iVar5 = r_emi_get_mem_addr_by_offset(0xc60);
          *pbVar2 = (byte)*(undefined2 *)(iVar5 + iVar3) & 1;
          iVar5 = *piVar9;
          uVar6 = uVar4 * 0x340000 >> 0x10;
          pvVar7 = (void *)r_emi_get_mem_addr_by_offset(uVar6 + 0xc78 & 0xffff);
          memcpy((void *)(iVar5 + 1),pvVar7,6);
          iVar5 = *piVar9;
          pvVar7 = (void *)r_emi_get_mem_addr_by_offset(uVar6 + 0xc62 & 0xffff);
          memcpy((void *)(iVar5 + 7),pvVar7,0x10);
        }
      }
    }
    iVar5 = r_emi_get_mem_addr_by_offset(0xc60);
    uVar1 = *(ushort *)(iVar5 + iVar3);
    iVar5 = r_emi_get_mem_addr_by_offset(0xc60);
    *(ushort *)(iVar3 + iVar5) = (ushort)(((uint)uVar1 << 0x11) >> 0x11);
    memset(&lld_rpa_res_list + uVar4 * 0xd,0,0xd);
    uVar8 = 0;
  }
  else {
    uVar8 = 2;
  }
  return uVar8;
}

