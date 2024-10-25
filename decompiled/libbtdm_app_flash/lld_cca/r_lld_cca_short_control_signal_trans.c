/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_short_control_signal_trans
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_cca_short_control_signal_trans(int param_1)

{
  byte bVar1;
  ushort uVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = p_lld_cca;
  if (param_1 != 0) {
    uVar2 = *(ushort *)(p_lld_cca + 0x14);
    uVar6 = *(ushort *)(p_lld_cca + 0xe) / 10;
    if (uVar2 < uVar6) {
      bVar1 = *(byte *)(p_lld_cca + 0xd);
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)(iVar5 + 0x16) = *(undefined2 *)((uint)bVar1 * 0x5a + 0x20 + iVar4);
      bVar1 = *(byte *)(p_lld_cca + 0xd);
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(short *)(iVar5 + (uint)bVar1 * 0x5a + 0x20) = (short)((uVar6 - uVar2) * 0x10000 >> 0x10);
    }
    else {
      pbVar3 = (byte *)(*(int *)(p_lld_cca + 0x28) + (uint)*(byte *)(p_lld_cca + 8) * 0xc);
      r_lld_cca_force_tx(1);
      *pbVar3 = *pbVar3 | 0x10;
    }
    return;
  }
  return;
}

