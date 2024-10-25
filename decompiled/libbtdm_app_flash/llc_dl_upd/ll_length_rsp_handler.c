/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_dl_upd.o -> ll_length_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ll_length_rsp_handler(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  ushort uVar3;
  
  iVar2 = r_llc_proc_id_get(0);
  uVar1 = 0x24;
  if (iVar2 == 7) {
    uVar1 = 0x20;
    if ((0x1a < *(ushort *)(param_2 + 2)) && (0x1a < *(ushort *)(param_2 + 6))) {
      if ((0x147 < *(ushort *)(param_2 + 4)) && (0x147 < *(ushort *)(param_2 + 8))) {
        iVar2 = r_llc_proc_get(param_1,0);
        uVar3 = *(ushort *)(iVar2 + 8);
        if (*(ushort *)(param_2 + 2) < *(ushort *)(iVar2 + 8)) {
          uVar3 = *(ushort *)(param_2 + 2);
        }
        *(ushort *)(iVar2 + 8) = uVar3;
        uVar3 = *(ushort *)(iVar2 + 10);
        if (*(ushort *)(param_2 + 4) < *(ushort *)(iVar2 + 10)) {
          uVar3 = *(ushort *)(param_2 + 4);
        }
        *(ushort *)(iVar2 + 10) = uVar3;
        uVar3 = *(ushort *)(iVar2 + 0xc);
        if (*(ushort *)(param_2 + 6) < *(ushort *)(iVar2 + 0xc)) {
          uVar3 = *(ushort *)(param_2 + 6);
        }
        *(ushort *)(iVar2 + 0xc) = uVar3;
        uVar3 = *(ushort *)(iVar2 + 0xe);
        if (*(ushort *)(param_2 + 8) < *(ushort *)(iVar2 + 0xe)) {
          uVar3 = *(ushort *)(param_2 + 8);
        }
        *(ushort *)(iVar2 + 0xe) = uVar3;
        uVar1 = 0;
      }
    }
    r_llc_loc_dl_upd_proc_continue(param_1,uVar1);
  }
  return uVar1;
}

