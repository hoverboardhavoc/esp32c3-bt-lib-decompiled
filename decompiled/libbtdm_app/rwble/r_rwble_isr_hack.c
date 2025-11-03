/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> rwble.o -> r_rwble_isr_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwble_isr_hack(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = _DAT_60031010;
  if (DAT_00011049 != '\0') {
    if ((_DAT_60031010 & 0x400000) != 0) {
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
    if (((uVar1 & 0x200000) != 0) &&
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
    if ((_DAT_600312d8 >> 5 & 0x1f) != 0) goto code_r0x000104bc;
  }
  return;
code_r0x000104bc:
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
           (ets_printf(__c_3,_DAT_60031054,_DAT_60031054), 0 < _g_bt_plf_log_level)) {
          ets_printf("BB DIAG0~5:%08x,%08x,%08x,%08x,%08x,%08x\n",_DAT_6001106c,_DAT_60011070,
                     _DAT_60011074,_DAT_60011078,_DAT_6001107c,_DAT_60011080);
        }
        if ((_DAT_60031060 & 0x200000) != 0) {
          if (0 < _g_bt_plf_log_level) {
            ets_printf("EM BASE ERR:%02x\n",_DAT_600312cc & 0x3fff);
          }
          (**(code **)(_r_plf_funcs_p + 0xac))(*(code **)(_r_plf_funcs_p + 0xac));
          (**(code **)(_r_plf_funcs_p + 0xb0))(*(code **)(_r_plf_funcs_p + 0xb0));
        }
        if (((_DAT_60031060 & 0x400000) != 0) && (0 < _g_bt_plf_log_level)) {
          ets_printf("FSMERR:%08x\n",_DAT_600312dc);
        }
        if (*(code **)(_r_ip_funcs_p + 0x744) == (code *)0x0) {
          (**(code **)(_r_plf_funcs_p + 0xc))
                    (_DAT_60031060,0,"rwble.c",0x201,*(code **)(_r_plf_funcs_p + 0xc));
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
    if ((uVar1 & 0x40000) != 0) {
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

