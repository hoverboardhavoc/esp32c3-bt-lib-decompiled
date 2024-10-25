/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_dl_upd.o -> ll_length_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ll_length_rsp_handler(undefined4 param_1,int param_2)

{
  int iVar1;
  ushort uVar2;
  undefined4 uVar3;
  
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(0,*(code **)(_r_ip_funcs_p + 0x678));
  uVar3 = 0x24;
  if (iVar1 == 7) {
    uVar3 = 0x20;
    if ((((0x1a < *(ushort *)(param_2 + 2)) && (0x1a < *(ushort *)(param_2 + 6))) &&
        (0x147 < *(ushort *)(param_2 + 4))) && (0x147 < *(ushort *)(param_2 + 8))) {
      iVar1 = (**(code **)(_r_ip_funcs_p + 0x674))(param_1,0,*(code **)(_r_ip_funcs_p + 0x674));
      uVar2 = *(ushort *)(iVar1 + 8);
      if (*(ushort *)(param_2 + 2) < *(ushort *)(iVar1 + 8)) {
        uVar2 = *(ushort *)(param_2 + 2);
      }
      *(ushort *)(iVar1 + 8) = uVar2;
      uVar2 = *(ushort *)(iVar1 + 10);
      if (*(ushort *)(param_2 + 4) < *(ushort *)(iVar1 + 10)) {
        uVar2 = *(ushort *)(param_2 + 4);
      }
      *(ushort *)(iVar1 + 10) = uVar2;
      uVar2 = *(ushort *)(iVar1 + 0xc);
      if (*(ushort *)(param_2 + 6) < *(ushort *)(iVar1 + 0xc)) {
        uVar2 = *(ushort *)(param_2 + 6);
      }
      *(ushort *)(iVar1 + 0xc) = uVar2;
      uVar2 = *(ushort *)(iVar1 + 0xe);
      if (*(ushort *)(param_2 + 8) < *(ushort *)(iVar1 + 0xe)) {
        uVar2 = *(ushort *)(param_2 + 8);
      }
      *(ushort *)(iVar1 + 0xe) = uVar2;
      uVar3 = 0;
    }
    (**(code **)(_r_ip_funcs_p + 0x5d4))(param_1,uVar3,*(code **)(_r_ip_funcs_p + 0x5d4));
  }
  return uVar3;
}

