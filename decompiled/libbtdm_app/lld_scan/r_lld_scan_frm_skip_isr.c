/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_frm_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_frm_skip_isr(int param_1)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  code *UNRECOVERED_JUMPTABLE;
  
  if (_lld_scan_env != 0) {
    iVar3 = *(int *)(_lld_scan_env + param_1 * 4);
    if (iVar3 != 0) {
      iVar4 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
      cVar1 = *(char *)(iVar3 + 0x3c);
      *(undefined1 *)(iVar3 + 0x3c) = 0;
      if (cVar1 == '\x02') {
                    /* WARNING: Could not recover jumptable at 0x00012f7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_ip_funcs_p + 0x3e4))(*(code **)(_r_ip_funcs_p + 0x3e4));
        return;
      }
      (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar3,1,*(code **)(_r_ip_funcs_p + 0x6b8));
      if (*(char *)(iVar3 + 0x3d) == '\x03') {
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
        if (*(char *)(iVar5 + 0x18) == '\0') {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0xa29,*(code **)(_r_plf_funcs_p + 8));
        }
        (**(code **)(_r_ip_funcs_p + 0x448))(param_1,*(code **)(_r_ip_funcs_p + 0x448));
        *(undefined1 *)(iVar3 + 0x3d) = 0;
      }
      bVar2 = rwip_priority;
      if ((uint)*(ushort *)(iVar3 + 0x30) << 1 <= (iVar4 - *(int *)(iVar3 + 0x28) & 0xfffffffU)) {
        if (0xff < (uint)*(byte *)(iVar3 + 0x16) + (uint)rwip_priority) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0xa34,*(code **)(_r_plf_funcs_p + 8));
        }
        *(int *)(iVar3 + 0x28) = iVar4;
        *(byte *)(iVar3 + 0x16) = bVar2 + *(char *)(iVar3 + 0x16);
      }
      iVar5 = _r_ip_funcs_p;
      if (*(char *)(iVar3 + 0x3e) == '\x01') {
        *(undefined1 *)(iVar3 + 0x3e) = 0;
                    /* WARNING: Could not recover jumptable at 0x00013082. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(iVar5 + 0x430))(param_1,iVar4,1,*(code **)(iVar5 + 0x430));
        return;
      }
      iVar3 = (**(code **)(_r_ip_funcs_p + 0x6b0))(iVar3,*(code **)(_r_ip_funcs_p + 0x6b0));
      if (iVar3 == 0) {
        return;
      }
      uVar6 = 0xa40;
      UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
      goto _L674;
    }
  }
  uVar6 = 0xa4e;
  UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
_L674:
                    /* WARNING: Could not recover jumptable at 0x00013064. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(0,"lld_scan.c",uVar6,UNRECOVERED_JUMPTABLE);
  return;
}

