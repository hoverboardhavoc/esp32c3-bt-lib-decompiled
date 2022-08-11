/*
 * Last changed at upstream commit 3b0038690a644498d6d80f1de8df0efff8cd8cf5
 * https://github.com/espressif/esp32c3-bt-lib/commit/3b0038690a644498d6d80f1de8df0efff8cd8cf5
 * Upstream date: 2022-08-11 21:28:16 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(f2e5d813)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_frm_isr_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_adv_frm_isr_hack(int param_1,int param_2)

{
  if ((*(int *)(&lld_adv_env + param_1 * 4) != 0) && (param_2 == 0)) {
    if (g_qa_test_config != '\0') {
      DAT_00010534 = DAT_00010534 + 1;
    }
  }
  r_lld_adv_frm_isr();
  return;
}

