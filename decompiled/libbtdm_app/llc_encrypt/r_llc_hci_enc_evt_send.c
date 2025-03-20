/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app -> llc_encrypt.o -> r_llc_hci_enc_evt_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_hci_enc_evt_send(undefined4 param_1,int param_2,int param_3)

{
  undefined1 *puVar1;
  
  if (param_3 == 0) {
    puVar1 = (undefined1 *)(**(code **)(_r_modules_funcs_p + 200))(0x1103,param_1,8,6);
    *(short *)(puVar1 + 2) = (short)param_1;
    puVar1[4] = param_2 == 0;
  }
  else {
    puVar1 = (undefined1 *)(**(code **)(_r_modules_funcs_p + 200))(0x1103,param_1,0x30,4);
    *(short *)(puVar1 + 2) = (short)param_1;
  }
  *puVar1 = (char)param_2;
                    /* WARNING: Could not recover jumptable at 0x00010c36. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x8c))();
  return;
}

