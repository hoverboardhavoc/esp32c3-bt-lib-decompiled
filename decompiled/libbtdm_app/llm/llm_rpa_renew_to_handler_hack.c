/*
 * Last changed at upstream commit 061e70c319576bf28b5695f5478dbe01ad18b18d
 * https://github.com/espressif/esp32c3-bt-lib/commit/061e70c319576bf28b5695f5478dbe01ad18b18d
 * Upstream date: 2024-09-21 10:42:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(63eb54d)
 * Source: libbtdm_app -> llm.o -> llm_rpa_renew_to_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 llm_rpa_renew_to_handler_hack(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x504))(*(code **)(_r_ip_funcs_p + 0x504));
  if (iVar1 != 0) {
    (**(code **)(_r_modules_funcs_p + 0xc4))
              (6,0,(uint)*(ushort *)(_p_llm_env + 0xc4) * 100,*(code **)(_r_modules_funcs_p + 0xc4))
    ;
  }
  (**(code **)(_r_ip_funcs_p + 0x294))(*(code **)(_r_ip_funcs_p + 0x294));
  return 0;
}

