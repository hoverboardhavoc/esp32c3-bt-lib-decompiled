/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> ll_connection_param_rsp_param_handler_pre
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ll_connection_param_rsp_param_handler_pre(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = r_llc_proc_id_get(0);
  if (iVar1 == 5) {
    iVar1 = r_llc_proc_get(param_1,0);
    *(undefined2 *)(iVar1 + 0x14) = *(undefined2 *)(param_2 + 0xc);
    *(undefined2 *)(iVar1 + 0x16) = *(undefined2 *)(param_2 + 0xe);
  }
  return 0;
}

