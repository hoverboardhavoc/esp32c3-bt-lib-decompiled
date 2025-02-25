/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app -> lld.o -> r_lld_update_rxbuf_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_update_rxbuf_isr(void)

{
  if (3 < _g_bt_plf_log_level) {
    ets_printf("RXBUF Update ISR  %04x %04x\n",_DAT_600312d0 & 0x7fff,_DAT_60031024 & 0x7fff);
  }
  _DAT_600312d0 = _DAT_600312d0 & 0xffff7fff;
                    /* WARNING: Could not recover jumptable at 0x00012c4a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0xe4))(0x215,1,0xff);
  return;
}

