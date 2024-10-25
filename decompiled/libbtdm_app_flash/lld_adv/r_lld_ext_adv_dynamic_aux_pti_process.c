/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_ext_adv_dynamic_aux_pti_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_ext_adv_dynamic_aux_pti_process(uint param_1,uint param_2,int param_3)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if (param_1 == 0) {
    do {
      param_2 = param_2 + 1 & 0xff;
      uVar5 = (uint)*(byte *)(param_3 + 7) << 8;
      if ((uVar5 & 0xfffff0ff) != 0) {
        r_assert_err(0,"lld_adv.c",0x33f);
      }
      iVar3 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar4 = param_2 * 0xe + 10;
      uVar2 = *(ushort *)(iVar3 + iVar4);
      iVar3 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar3 + iVar4) = uVar2 & 0xf0ff | (ushort)uVar5;
      uVar5 = (uint)*(byte *)(param_3 + 8) << 0xc;
      if ((uVar5 & 0xffffefff) != 0) {
        r_assert_err(0,"lld_adv.c",0x333);
      }
      iVar3 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar2 = *(ushort *)(iVar3 + iVar4);
      iVar3 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar3 + iVar4) = uVar2 & 0xefff | (ushort)uVar5;
      iVar3 = r_emi_get_mem_addr_by_offset(0x1400);
    } while ((*(ushort *)(iVar3 + param_2 * 0xe) & 0x7fff) != 0);
  }
  else {
    if ((param_1 & 1) == 0) {
      if ((param_1 & 2) == 0) {
        return;
      }
      uVar5 = (uint)*(byte *)(param_3 + 9) << 8;
      if ((uVar5 & 0xf000) != 0) {
        r_assert_err(0,"lld_adv.c",0x33f);
      }
      iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar3 = (param_2 + 1 & 0xff) * 0xe + 10;
      uVar2 = *(ushort *)(iVar4 + iVar3);
      iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar4 + iVar3) = uVar2 & 0xf0ff | (ushort)uVar5;
      bVar1 = *(byte *)(param_3 + 10);
    }
    else {
      uVar5 = (uint)*(byte *)(param_3 + 0xb) << 8;
      if ((uVar5 & 0xf000) != 0) {
        r_assert_err(0,"lld_adv.c",0x33f);
      }
      iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar3 = (param_2 + 1 & 0xff) * 0xe + 10;
      uVar2 = *(ushort *)(iVar4 + iVar3);
      iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar4 + iVar3) = uVar2 & 0xf0ff | (ushort)uVar5;
      bVar1 = *(byte *)(param_3 + 0xc);
    }
    if (((uint)bVar1 << 0xc & 0xffffefff) != 0) {
      r_assert_err(0,"lld_adv.c",0x333);
    }
    iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar2 = *(ushort *)(iVar4 + iVar3);
    iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar4 + iVar3) = uVar2 & 0xefff | (ushort)((uint)bVar1 << 0xc);
  }
  return;
}

