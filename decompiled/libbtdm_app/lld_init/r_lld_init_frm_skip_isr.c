/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app -> lld_init.o -> r_lld_init_frm_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_frm_skip_isr(int param_1)

{
  char cVar1;
  int iVar2;
  byte bVar3;
  code *UNRECOVERED_JUMPTABLE;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  if (_lld_init_env != 0) {
    iVar4 = *(int *)(_lld_init_env + param_1 * 4);
    if (iVar4 != 0) {
      iVar5 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
      cVar1 = *(char *)(iVar4 + 0x31);
      *(undefined1 *)(iVar4 + 0x31) = 0;
      if (cVar1 == '\x02') {
                    /* WARNING: Could not recover jumptable at 0x000115c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_ip_funcs_p + 0x454))();
        return;
      }
      (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar4,1,*(code **)(_r_ip_funcs_p + 0x6b8));
      bVar3 = rwip_priority;
      if ((uint)*(ushort *)(iVar4 + 0x2c) << 1 <= (iVar5 - *(int *)(iVar4 + 0x28) & 0xfffffffU)) {
        if (0xff < (uint)*(byte *)(iVar4 + 0x16) + (uint)rwip_priority) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x4ec,*(code **)(_r_plf_funcs_p + 8));
        }
        *(int *)(iVar4 + 0x28) = iVar5;
        *(byte *)(iVar4 + 0x16) = bVar3 + *(char *)(iVar4 + 0x16);
      }
      iVar2 = _r_ip_funcs_p;
      if (*(char *)(iVar4 + 0x3d) == '\x01') {
        *(undefined1 *)(iVar4 + 0x3d) = 0;
                    /* WARNING: Could not recover jumptable at 0x0001168a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(iVar2 + 0x48c))(param_1,iVar5,1);
        return;
      }
      iVar4 = (**(code **)(_r_ip_funcs_p + 0x6b0))(iVar4,*(code **)(_r_ip_funcs_p + 0x6b0));
      if (iVar4 == 0) {
        return;
      }
      uVar6 = 0x4f8;
      UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
      goto _L232;
    }
  }
  uVar6 = 0x506;
  UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
_L232:
                    /* WARNING: Could not recover jumptable at 0x0001166c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(0,"lld_init.c",uVar6);
  return;
}

