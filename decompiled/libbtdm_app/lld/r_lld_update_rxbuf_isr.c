/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
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
                    /* WARNING: Could not recover jumptable at 0x00012c10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0xe4))(0x215,1,0xff);
  return;
}

