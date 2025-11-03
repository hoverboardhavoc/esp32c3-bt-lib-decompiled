/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_process_pkt_rx_ext_adv
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_process_pkt_rx_ext_adv(int param_1,uint param_2,int param_3,char *param_4)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ushort uVar8;
  
  if (param_2 < 7) {
    return;
  }
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x7f8))
                    (1,param_1,param_2,param_3,param_4,*(code **)(_r_ip_funcs_p + 0x7f8));
  if (iVar2 != 0) {
    return;
  }
  iVar6 = *(int *)(_lld_scan_env + param_1 * 4);
  iVar7 = param_3 * 0x14 + 0x10;
  iVar5 = param_3 * 0x14 + 4;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar8 = *(ushort *)(iVar2 + iVar7) & 0x3f;
  *param_4 = (char)uVar8;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  if (*(ushort *)(iVar2 + iVar5) >> 8 <= uVar8) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x857,*(code **)(_r_plf_funcs_p + 8));
  }
  cVar3 = *param_4;
  if (cVar3 != '\0') {
    cVar3 = cVar3 + -1;
  }
  param_4[4] = cVar3;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  cVar3 = *param_4;
  param_4[5] = ((char)((ushort)*(undefined2 *)(iVar2 + iVar5) >> 8) - cVar3) + -1;
  *(undefined1 *)(iVar6 + 0x3e) = 0;
  if (cVar3 != '\0') {
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    *(undefined2 *)(param_4 + 6) = *(undefined2 *)(iVar2 + iVar7);
  }
  bVar1 = *(byte *)(iVar6 + 0x3d);
  if (bVar1 == 2) {
    pcVar4 = *(code **)(_r_ip_funcs_p + 0x418);
  }
  else if (bVar1 < 3) {
    if (bVar1 == 0) {
      pcVar4 = *(code **)(_r_ip_funcs_p + 0x410);
    }
    else {
      pcVar4 = *(code **)(_r_ip_funcs_p + 0x414);
    }
  }
  else {
    if (bVar1 != 3) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x87e,*(code **)(_r_plf_funcs_p + 8));
      goto _L531;
    }
    pcVar4 = *(code **)(_r_ip_funcs_p + 0x41c);
  }
  (*pcVar4)(param_1,param_2,param_3,param_4,pcVar4);
_L531:
                    /* WARNING: Could not recover jumptable at 0x00012494. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x7f8))
            (0,param_1,param_2,param_3,param_4,*(code **)(_r_ip_funcs_p + 0x7f8));
  return;
}

