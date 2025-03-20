/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app -> osi.o -> btdm_osi_funcs_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 btdm_osi_funcs_register(int *param_1)

{
  undefined4 uVar1;
  char *pcVar2;
  
  if (param_1 == (int *)0x0) {
    return 0xffffffff;
  }
  if (3 < _g_bt_plf_log_level) {
    ets_printf("MAGIC %08x VERSION %08x\n",0xfadebead,0x10009);
  }
  if (*param_1 == -0x5214153) {
    if (param_1[1] == 0x10009) {
      _r_osi_funcs_p = param_1;
      return 0;
    }
    uVar1 = 0xfffffffd;
    if (_g_bt_plf_log_level < 1) {
      return 0xfffffffd;
    }
    pcVar2 = "OSI Version mismatch: %08x\n";
  }
  else {
    uVar1 = 0xfffffffe;
    if (_g_bt_plf_log_level < 1) {
      return 0xfffffffe;
    }
    pcVar2 = "OSI Magic mismatch: %08x\n";
  }
  ets_printf(pcVar2);
  return uVar1;
}

