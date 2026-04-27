/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_process_pkt_rx_aux_scan_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_process_pkt_rx_aux_scan_rsp(int param_1,int param_2,char *param_3)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  void *__src;
  undefined1 *puVar6;
  byte bVar7;
  undefined1 uVar8;
  int iVar9;
  undefined4 auStack_34 [4];
  
  iVar9 = param_2 * 0x14;
  iVar3 = *(int *)(_lld_scan_env + param_1 * 4);
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  sVar1 = *(short *)(iVar9 + 0x12 + iVar5);
  bVar7 = param_3[5];
  *(undefined1 *)(iVar3 + 0x6e) = 1;
  *(ushort *)(iVar3 + 0x36) = (ushort)bVar7;
  *(byte *)(iVar3 + 0x6d) = *(byte *)(iVar3 + 0x6d) | 8;
  if (*param_3 == '\0') {
    *(undefined1 *)(iVar3 + 0x6e) = 0;
    *(undefined1 *)(iVar3 + 0x3d) = 0;
    return;
  }
  if ((*(ushort *)(param_3 + 6) & 0x100) == 0) {
    sVar4 = 0;
  }
  else {
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    bVar7 = (byte)(*(ushort *)(iVar9 + 4 + iVar5) >> 6) & 1;
    param_3[8] = bVar7;
    *(byte *)(iVar3 + 0x6f) = bVar7;
    if (((*(char *)(_lld_scan_env + 0x15) == '\x01') ||
        ((*(char *)(_lld_scan_env + 0x15) == '\x03' && ((*(ushort *)(param_3 + 6) & 0x200) == 0))))
       && (iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc)),
          (*(ushort *)(iVar9 + 2 + iVar5) >> 0xb & 1) == 0)) {
      *(undefined1 *)(iVar3 + 0x6e) = 0xff;
      return;
    }
    sVar4 = 6;
  }
  uVar2 = *(ushort *)(param_3 + 6);
  if ((uVar2 & 0x200) != 0) {
    sVar4 = sVar4 + 6;
  }
  if ((uVar2 & 0x400) != 0) {
    sVar4 = sVar4 + 1;
  }
  if ((uVar2 >> 0xb & 1) != 0) {
    sVar4 = sVar4 + 2;
  }
  if ((uVar2 & 0x1000) == 0) {
    *(undefined1 *)(iVar3 + 0x6e) = 0;
    *(undefined1 *)(iVar3 + 0x3d) = 0;
    goto _L459;
  }
  __src = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                            (sVar1 + sVar4,*(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(auStack_34,__src,3);
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  if ((*(ushort *)(iVar9 + 2 + iVar5) >> 9 & 1) == 0) {
    iVar5 = (**(code **)(_r_ip_funcs_p + 0x224))
                      (iVar3 + 0x48,param_2,*(code **)(_r_ip_funcs_p + 0x224));
    uVar8 = 1;
    if (iVar5 != 0) goto _L478;
    *(undefined1 *)(iVar3 + 0x6e) = 2;
  }
  else {
    *(undefined4 *)(iVar3 + 0x2c) = auStack_34[0];
    uVar8 = 2;
_L478:
    *(undefined1 *)(iVar3 + 0x3e) = uVar8;
  }
  *(undefined1 *)(iVar3 + 0x3d) = 3;
  sVar4 = sVar4 + 3;
_L459:
  if ((*(ushort *)(param_3 + 6) & 0x2000) != 0) {
    sVar4 = sVar4 + 0x12;
  }
  if ((*(ushort *)(param_3 + 6) & 0x4000) != 0) {
    puVar6 = (undefined1 *)
             (**(code **)(_r_plf_funcs_p + 0xbc))(sVar1 + sVar4,*(code **)(_r_plf_funcs_p + 0xbc));
    *(undefined1 *)(iVar3 + 0x73) = *puVar6;
  }
  return;
}

