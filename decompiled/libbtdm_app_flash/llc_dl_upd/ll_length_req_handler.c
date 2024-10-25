/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_dl_upd.o -> ll_length_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ll_length_req_handler(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = r_llc_proc_id_get(1);
  if (iVar1 == 0) {
    uVar2 = 0x20;
    if ((((0x1a < *(ushort *)(param_2 + 2)) && (0x1a < *(ushort *)(param_2 + 6))) &&
        (0x147 < *(ushort *)(param_2 + 4))) &&
       ((((ushort)(*(short *)(param_2 + 8) - 0x148U) < 0x4149 && (*(ushort *)(param_2 + 2) < 0xfc))
        && ((*(ushort *)(param_2 + 6) < 0xfc && (*(ushort *)(param_2 + 4) < 0x4291)))))) {
      r_llc_rem_dl_upd_proc(param_1);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0x24;
  }
  return uVar2;
}

