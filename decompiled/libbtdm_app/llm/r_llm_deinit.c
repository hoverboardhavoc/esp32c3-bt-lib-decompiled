/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app -> llm.o -> r_llm_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_deinit(int param_1)

{
  if (param_1 == 2) {
                    /* WARNING: Could not recover jumptable at 0x000109a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x548))(*(code **)(_r_ip_funcs_p + 0x548));
    return;
  }
  return;
}

