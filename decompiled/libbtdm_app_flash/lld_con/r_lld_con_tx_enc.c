/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_tx_enc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_tx_enc(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar4 != 0) {
    iVar3 = r_emi_get_mem_addr_by_offset(0x400);
    iVar2 = param_1 * 0x5a + 2;
    uVar1 = *(ushort *)(iVar3 + iVar2);
    iVar3 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar3 + iVar2) = uVar1 & 0xfdff | (ushort)(param_2 << 9);
    *(ushort *)(iVar4 + 0x84) = *(ushort *)(iVar4 + 0x84) & 0xffbf | (ushort)(param_2 << 6);
  }
  return;
}

