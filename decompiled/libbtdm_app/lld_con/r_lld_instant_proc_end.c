/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> lld_con.o -> r_lld_instant_proc_end
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_instant_proc_end(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  cVar1 = *(char *)(iVar2 + 0x46);
  if (cVar1 == '\x02') {
    pcVar4 = *(code **)(_r_modules_funcs_p + 0xe4);
    uVar3 = 0x210;
  }
  else {
    if (cVar1 != '\x03') {
      if (cVar1 == '\x01') {
        (**(code **)(_r_modules_funcs_p + 0xe4))
                  (0x20f,param_1 << 8 | 1,0xff,*(code **)(_r_modules_funcs_p + 0xe4));
        (**(code **)(_r_ip_funcs_p + 0x34c))(param_1,*(code **)(_r_ip_funcs_p + 0x34c));
        (**(code **)(_r_ip_funcs_p + 0x3c4))
                  (param_1,*(undefined1 *)(iVar2 + 0x94),*(undefined4 *)(iVar2 + 100),
                   *(code **)(_r_ip_funcs_p + 0x3c4));
      }
      else {
        (**(code **)(_r_plf_funcs_p + 0x10))
                  (0,0,"lld_con.c",0x85a,*(code **)(_r_plf_funcs_p + 0x10));
      }
      goto _L320;
    }
    *(undefined1 *)(iVar2 + 0x93) = *(undefined1 *)(iVar2 + 0x35);
    *(undefined1 *)(iVar2 + 0x94) = *(undefined1 *)(iVar2 + 0x34);
    (**(code **)(_r_ip_funcs_p + 0x34c))(*(code **)(_r_ip_funcs_p + 0x34c));
    (**(code **)(_r_ip_funcs_p + 0x3c4))
              (param_1,*(undefined1 *)(iVar2 + 0x94),*(undefined4 *)(iVar2 + 100),
               *(code **)(_r_ip_funcs_p + 0x3c4));
    pcVar4 = *(code **)(_r_modules_funcs_p + 0xe4);
    uVar3 = 0x211;
  }
  (*pcVar4)(uVar3,param_1 << 8 | 1,0xff,pcVar4);
_L320:
  *(undefined1 *)(iVar2 + 0x46) = 0;
  return;
}

