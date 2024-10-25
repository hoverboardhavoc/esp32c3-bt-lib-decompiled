/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_disconnect.o -> llc_stopped_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 llc_stopped_ind_handler(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(&llc_env + (param_1 >> 8) * 4);
  uVar1 = param_1 >> 8 & 0xff;
  if (iVar2 == 0) {
    r_assert_param(0,"llc_disconnect.c",0x17b);
  }
  r_llc_disconnect_end(uVar1,0,*(undefined1 *)(iVar2 + 0x46));
  r_llc_cleanup(uVar1,0);
  r_llm_link_disc(uVar1);
  return 0;
}

