/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> eif.o -> r_h4tl_eif_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_h4tl_eif_register(int *param_1)

{
  undefined4 uVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  if (param_1 == (int *)0x0) {
    return 0xffffffff;
  }
  if (3 < _g_bt_plf_log_level) {
    ets_printf("MAGIC %08x VERSION %08x\n",0xfadebead,0x10000);
  }
  uVar3 = 0xfadebead;
  if (*param_1 == -0x5214153) {
    if (param_1[1] == 0x10000) {
      _r_h4tl_eif_p = param_1;
      return 0;
    }
    uVar1 = 0xfffffffd;
    if (_g_bt_plf_log_level < 1) {
      return 0xfffffffd;
    }
    uVar3 = 0x10000;
    pcVar2 = "H4TL EIF Version mismatch: %08x\n";
  }
  else {
    uVar1 = 0xfffffffe;
    if (_g_bt_plf_log_level < 1) {
      return 0xfffffffe;
    }
    pcVar2 = "H4TL EIF Magic mismatch: %08x\n";
  }
  ets_printf(pcVar2,uVar3);
  return uVar1;
}

