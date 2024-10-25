/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_ext_adv_dynamic_aux_pti_process_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_ext_adv_dynamic_aux_pti_process_eco(uint param_1,uint param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  r_lld_ext_adv_dynamic_aux_pti_process();
  if (((param_1 != 0) && ((param_1 & 1) == 0)) && ((param_1 & 2) != 0)) {
    do {
      param_2 = param_2 + 1 & 0xff;
      uVar4 = (uint)*(byte *)(param_3 + 9) << 8;
      if ((uVar4 & 0xfffff0ff) != 0) {
        r_assert_err(0,"lld_adv.c",0x33f);
      }
      iVar2 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar3 = param_2 * 0xe + 10;
      uVar1 = *(ushort *)(iVar2 + iVar3);
      iVar2 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar2 + iVar3) = uVar1 & 0xf0ff | (ushort)uVar4;
      uVar4 = (uint)*(byte *)(param_3 + 10) << 0xc;
      if ((uVar4 & 0xffffefff) != 0) {
        r_assert_err(0,"lld_adv.c",0x333);
      }
      iVar2 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar1 = *(ushort *)(iVar2 + iVar3);
      iVar2 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar2 + iVar3) = uVar1 & 0xefff | (ushort)uVar4;
      iVar2 = r_emi_get_mem_addr_by_offset(0x1400);
    } while ((*(ushort *)(iVar2 + param_2 * 0xe) & 0x7fff) != 0);
  }
  return;
}

