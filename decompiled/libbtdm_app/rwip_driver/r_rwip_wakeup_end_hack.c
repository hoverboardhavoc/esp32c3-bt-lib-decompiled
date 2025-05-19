/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app -> rwip_driver.o -> r_rwip_wakeup_end_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_wakeup_end_hack(void)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  
  if (*(code **)(_r_osi_funcs_p + 0xa4) != (code *)0x0) {
    (**(code **)(_r_osi_funcs_p + 0xa4))();
  }
  iVar2 = (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
  _DAT_6003100c = _DAT_6003100c & 0xfffffffe;
  (**(code **)(_r_ip_funcs_p + 0x134))(*(code **)(_r_ip_funcs_p + 0x134));
  uVar1 = _DAT_6003100c | 0x1188;
  if (_rwip_env != -1) {
    if ((iVar2 - _rwip_env & 0xfffffffU) < 0x7ffffff) {
      _DAT_6003100c = _DAT_6003100c | 0x1188;
      (**(code **)(_r_modules_funcs_p + 0x2d0))(*(code **)(_r_modules_funcs_p + 0x2d0));
      uVar1 = _DAT_6003100c;
    }
    else {
      uVar1 = _DAT_6003100c | 0x1588;
    }
  }
  _DAT_6003100c = uVar1;
  if (_rwip_param != -1) {
    if ((iVar2 - _rwip_param & 0xfffffffU) < 0x7ffffff) {
      (**(code **)(_r_modules_funcs_p + 0x2d8))(*(code **)(_r_modules_funcs_p + 0x2d8));
    }
    else {
      _DAT_6003100c = _DAT_6003100c & 0xfffff7ff | 0x800;
    }
  }
  if (_rwip_prog_delay != -1) {
    if ((iVar2 - _rwip_prog_delay & 0xfffffffU) < 0x7ffffff) {
      (**(code **)(_r_modules_funcs_p + 0x2c8))(*(code **)(_r_modules_funcs_p + 0x2c8));
    }
    else {
      _DAT_6003100c = _DAT_6003100c | 0x200;
    }
  }
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (*(char *)(iVar2 + 0x17) == '\x01') {
    pcVar3 = *(code **)(_r_plf_funcs_p + 0xd8);
  }
  else {
    iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (*(char *)(iVar2 + 0x17) != '\0') goto _L73;
    pcVar3 = *(code **)(_r_modules_funcs_p + 0x8c);
  }
  (*pcVar3)(pcVar3);
_L73:
  (**(code **)(_r_modules_funcs_p + 0x2b0))(1,*(code **)(_r_modules_funcs_p + 0x2b0));
  _btdm_pwr_state = 4;
                    /* WARNING: Could not recover jumptable at 0x0001059c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 0x2c))(3,*(code **)(_r_plf_funcs_p + 0x2c));
  return;
}

