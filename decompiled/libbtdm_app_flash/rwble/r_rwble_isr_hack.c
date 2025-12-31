/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> rwble.o -> r_rwble_isr_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwble_isr_hack(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = _DAT_60031010;
  if (DAT_00011045 != '\0') {
    if ((_DAT_60031010 & 0x400000) != 0) {
      r_ble_log_internal_x1(0x602d006f,_DAT_60031010);
      _DAT_600312d8 = _DAT_600312d8 | 0x80000000;
      _DAT_60031018 = 0x7fffff;
      if ((uVar2 & 0x1fffff) == 1) {
        if (1 < _g_bt_plf_log_level) {
          ets_printf("IRQ FIFO OVERFLOW\n");
        }
      }
      else {
        r_assert_err(0,"rwble.c",0x1a6);
      }
    }
    if ((uVar2 & 0x200000) != 0) {
      uVar3 = _DAT_600312d8 >> 1 & 0xf;
      uVar1 = _DAT_600312d8 >> 5 & 0x1f;
      r_ble_log_internal_x2(0x602d0070,uVar2,uVar3 << 8 | uVar1);
      _DAT_60031018 = _DAT_60031018 & 0xffdfffff | 0x200000;
      if (1 < _g_bt_plf_log_level) {
        ets_printf("IRQ FIFO ALMOST FULL,cnt:%u,rem:%u\n",uVar1,uVar3);
      }
    }
  }
  do {
    while (DAT_00011045 == '\0') {
      uVar2 = _DAT_60031010;
      if (_DAT_60031010 == 0) {
        return;
      }
_L82:
      if ((uVar2 & 0x81e89) != 0) {
        r_rwip_isr(uVar2);
      }
      if ((uVar2 & 0x100) != 0) {
        _DAT_60031018 = 0x100;
        r_ble_log_internal_x2(0x802d0073,uVar2,_DAT_60031060);
        iVar4 = r_rwble_isr_hw_fixed(_DAT_60031060);
        if (iVar4 != 0) {
          _DAT_60031050 = 0x838295a8;
          if ((0 < _g_bt_plf_log_level) &&
             (ets_printf(__c_3,_DAT_60031054,_DAT_60031054), 0 < _g_bt_plf_log_level)) {
            ets_printf("BB DIAG0~5:%08x,%08x,%08x,%08x,%08x,%08x\n",_DAT_6001106c,_DAT_60011070,
                       _DAT_60011074,_DAT_60011078,_DAT_6001107c,_DAT_60011080);
          }
          if ((_DAT_60031060 & 0x200000) != 0) {
            if (0 < _g_bt_plf_log_level) {
              ets_printf("EM BASE ERR:%02x\n",_DAT_600312cc & 0x3fff);
            }
            r_emi_em_base_reg_show();
            r_emi_base_reg_lut_show();
          }
          if (((_DAT_60031060 & 0x400000) != 0) && (0 < _g_bt_plf_log_level)) {
            ets_printf("FSMERR:%08x\n",_DAT_600312dc);
          }
          r_assert_param(_DAT_60031060,0,"rwble.c",0x1fb);
        }
      }
      if ((uVar2 & 2) != 0) {
        _DAT_60031018 = 2;
        r_sch_prog_tx_isr(0xff);
      }
      if ((uVar2 & 4) != 0) {
        _DAT_60031018 = 4;
        r_sch_prog_rx_isr(0xff);
      }
      if ((uVar2 & 0x40000) != 0) {
        _DAT_60031018 = _DAT_60031018 & 0xfffbffff | 0x40000;
        r_lld_update_rxbuf_isr();
      }
      if ((uVar2 & 0x40) != 0) {
        _DAT_60031018 = 0x40;
        r_sch_prog_skip_isr(0xff);
      }
      if ((uVar2 & 0x20) != 0) {
        _DAT_60031018 = 0x20;
        r_sch_prog_end_isr_hack(0xff);
      }
      r_ble_log_internal_x1(0x204d0074,uVar2);
    }
    uVar2 = (_DAT_600312d8 << 1) >> 0xb;
    if ((_DAT_600312d8 >> 5 & 0x1f) == 0) {
      r_ble_log_internal_x3(0x204d0071,_DAT_600312d8,_DAT_60031010,0);
      return;
    }
    _DAT_600312d8 = _DAT_600312d8 | 1;
    if (uVar2 != 0) goto _L82;
    r_ble_log_internal_x3(0x204d0072,_DAT_600312d8,_DAT_60031010,0);
  } while( true );
}

