/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_process_pkt_rx_ext_adv
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_process_pkt_rx_ext_adv(int param_1,uint param_2,int param_3,byte *param_4)

{
  char cVar1;
  int iVar2;
  byte bVar3;
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
  iVar7 = *(int *)(_lld_scan_env + param_1 * 4);
  iVar6 = param_3 * 0x14 + 0x10;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar5 = param_3 * 0x14 + 4;
  uVar8 = *(ushort *)(iVar2 + iVar6) & 0x3f;
  *param_4 = (byte)uVar8;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  if (*(ushort *)(iVar2 + iVar5) >> 8 <= uVar8) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x80a,*(code **)(_r_plf_funcs_p + 8));
  }
  bVar3 = *param_4;
  if (bVar3 != 0) {
    bVar3 = bVar3 - 1;
  }
  param_4[4] = bVar3;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  bVar3 = *param_4;
  param_4[5] = (char)((ushort)*(undefined2 *)(iVar2 + iVar5) >> 8) + ~bVar3;
  *(undefined1 *)(iVar7 + 0x3e) = 0;
  if (bVar3 != 0) {
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    *(undefined2 *)(param_4 + 6) = *(undefined2 *)(iVar2 + iVar6);
  }
  cVar1 = *(char *)(iVar7 + 0x3d);
  if (cVar1 == '\x01') {
    pcVar4 = *(code **)(_r_ip_funcs_p + 0x414);
  }
  else if (cVar1 == '\0') {
    pcVar4 = *(code **)(_r_ip_funcs_p + 0x410);
  }
  else if (cVar1 == '\x02') {
    pcVar4 = *(code **)(_r_ip_funcs_p + 0x418);
  }
  else {
    if (cVar1 != '\x03') {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x831,*(code **)(_r_plf_funcs_p + 8));
      goto _L532;
    }
    pcVar4 = *(code **)(_r_ip_funcs_p + 0x41c);
  }
  (*pcVar4)(param_1,param_2,param_3,param_4,pcVar4);
_L532:
                    /* WARNING: Could not recover jumptable at 0x00012478. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x7f8))(0,param_1,param_2,param_3,param_4);
  return;
}

