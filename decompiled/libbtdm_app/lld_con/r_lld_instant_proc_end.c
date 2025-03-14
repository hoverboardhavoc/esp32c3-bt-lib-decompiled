/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
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
  undefined4 uVar2;
  code *pcVar3;
  int iVar4;
  
  iVar4 = *(int *)(&lld_con_env + param_1 * 4);
  cVar1 = *(char *)(iVar4 + 0x46);
  if (cVar1 == '\x02') {
    pcVar3 = *(code **)(_r_modules_funcs_p + 0xe4);
    uVar2 = 0x210;
  }
  else {
    if (cVar1 != '\x03') {
      if (cVar1 == '\x01') {
        (**(code **)(_r_modules_funcs_p + 0xe4))
                  (0x20f,param_1 << 8 | 1,0xff,*(code **)(_r_modules_funcs_p + 0xe4));
        (**(code **)(_r_ip_funcs_p + 0x34c))(param_1,*(code **)(_r_ip_funcs_p + 0x34c));
        (**(code **)(_r_ip_funcs_p + 0x3c4))
                  (param_1,*(undefined1 *)(iVar4 + 0x94),*(undefined4 *)(iVar4 + 100),
                   *(code **)(_r_ip_funcs_p + 0x3c4));
      }
      else {
        (**(code **)(_r_plf_funcs_p + 0x10))
                  (0,0,"lld_con.c",0x805,*(code **)(_r_plf_funcs_p + 0x10));
      }
      goto _L326;
    }
    *(undefined1 *)(iVar4 + 0x93) = *(undefined1 *)(iVar4 + 0x35);
    *(undefined1 *)(iVar4 + 0x94) = *(undefined1 *)(iVar4 + 0x34);
    (**(code **)(_r_ip_funcs_p + 0x34c))(*(code **)(_r_ip_funcs_p + 0x34c));
    (**(code **)(_r_ip_funcs_p + 0x3c4))
              (param_1,*(undefined1 *)(iVar4 + 0x94),*(undefined4 *)(iVar4 + 100),
               *(code **)(_r_ip_funcs_p + 0x3c4));
    pcVar3 = *(code **)(_r_modules_funcs_p + 0xe4);
    uVar2 = 0x211;
  }
  (*pcVar3)(uVar2,param_1 << 8 | 1,0xff,pcVar3);
_L326:
  *(undefined1 *)(iVar4 + 0x46) = 0;
  return;
}

