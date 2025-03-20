/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app -> rwble.o -> r_rwble_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwble_isr(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = _DAT_60031010;
  if (DAT_00011049 != '\0') {
    if ((int)(_DAT_60031010 << 9) < 0) {
      _DAT_600312d8 = _DAT_600312d8 | 0x80000000;
      _DAT_60031018 = 0x7fffff;
      if ((_DAT_60031010 & 0x1fffff) == 1) {
        if (1 < _g_bt_plf_log_level) {
          ets_printf("IRQ FIFO OVERFLOW\n");
        }
      }
      else {
        (**(code **)(_r_plf_funcs_p + 8))(0,"rwble.c",0x1a6,*(code **)(_r_plf_funcs_p + 8));
      }
    }
    if (((int)(uVar1 << 10) < 0) &&
       (_DAT_60031018 = _DAT_60031018 & 0xffdfffff | 0x200000, 1 < _g_bt_plf_log_level)) {
      ets_printf("IRQ FIFO ALMOST FULL,cnt:%u,rem:%u\n",_DAT_600312d8 >> 5 & 0x1f,
                 _DAT_600312d8 >> 1 & 0xf);
    }
  }
_L81:
  if (DAT_00011049 == '\0') {
    uVar1 = _DAT_60031010;
    if (_DAT_60031010 != 0) goto _L85;
  }
  else {
    uVar1 = (_DAT_600312d8 << 1) >> 0xb;
    if ((_DAT_600312d8 >> 5 & 0x1f) != 0) goto code_r0x000104b0;
  }
  return;
code_r0x000104b0:
  _DAT_600312d8 = _DAT_600312d8 | 1;
  if (uVar1 != 0) {
_L85:
    if ((uVar1 & 0x81e89) != 0) {
      (**(code **)(_r_modules_funcs_p + 0x2a8))(uVar1,*(code **)(_r_modules_funcs_p + 0x2a8));
    }
    if ((uVar1 & 0x100) != 0) {
      _DAT_60031018 = 0x100;
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x90c))(_DAT_60031060,*(code **)(_r_ip_funcs_p + 0x90c));
      if (iVar2 != 0) {
        _DAT_60031050 = 0x838295a8;
        if ((0 < _g_bt_plf_log_level) &&
           (ets_printf("DIAG0~1:%08x,%08x\n",_DAT_60031054,_DAT_60031054), 0 < _g_bt_plf_log_level))
        {
          ets_printf("BB DIAG0~5:%08x,%08x,%08x,%08x,%08x,%08x\n",_DAT_6001106c,_DAT_60011070,
                     _DAT_60011074,_DAT_60011078,_DAT_6001107c,_DAT_60011080);
        }
        if (_DAT_60031060 << 10 < 0) {
          if (0 < _g_bt_plf_log_level) {
            ets_printf("EM BASE ERR:%02x\n",_DAT_600312cc & 0x3fff);
          }
          (**(code **)(_r_plf_funcs_p + 0xac))(*(code **)(_r_plf_funcs_p + 0xac));
          (**(code **)(_r_plf_funcs_p + 0xb0))(*(code **)(_r_plf_funcs_p + 0xb0));
        }
        if ((_DAT_60031060 << 9 < 0) && (0 < _g_bt_plf_log_level)) {
          ets_printf("FSMERR:%08x\n",_DAT_600312dc);
        }
        if (*(code **)(_r_ip_funcs_p + 0x744) == (code *)0x0) {
          (**(code **)(_r_plf_funcs_p + 0xc))
                    (_DAT_60031060,0,"rwble.c",0x1fc,*(code **)(_r_plf_funcs_p + 0xc));
        }
        else {
          (**(code **)(_r_ip_funcs_p + 0x744))();
        }
      }
    }
    if ((uVar1 & 2) != 0) {
      _DAT_60031018 = 2;
      (**(code **)(_r_ip_funcs_p + 0x6d4))(0xff,*(code **)(_r_ip_funcs_p + 0x6d4));
    }
    if ((uVar1 & 4) != 0) {
      _DAT_60031018 = 4;
      (**(code **)(_r_ip_funcs_p + 0x6cc))(0xff,*(code **)(_r_ip_funcs_p + 0x6cc));
    }
    if ((int)(uVar1 << 0xd) < 0) {
      _DAT_60031018 = _DAT_60031018 & 0xfffbffff | 0x40000;
      (**(code **)(_r_ip_funcs_p + 0x2b8))(*(code **)(_r_ip_funcs_p + 0x2b8));
    }
    if ((uVar1 & 0x40) != 0) {
      _DAT_60031018 = 0x40;
      (**(code **)(_r_ip_funcs_p + 0x6d0))(0xff,*(code **)(_r_ip_funcs_p + 0x6d0));
    }
    if ((uVar1 & 0x20) != 0) {
      _DAT_60031018 = 0x20;
      (**(code **)(_r_ip_funcs_p + 0x6c0))(0xff,*(code **)(_r_ip_funcs_p + 0x6c0));
    }
  }
  goto _L81;
}

