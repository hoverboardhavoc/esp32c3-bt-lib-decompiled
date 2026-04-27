/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_evt_start_cbk_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_evt_start_cbk_eco(int param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  ushort uVar7;
  uint uVar8;
  byte bStack_51;
  uint uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  uint uStack_40;
  undefined1 uStack_3c;
  undefined1 uStack_3b;
  undefined1 uStack_3a;
  undefined1 uStack_39;
  byte bStack_38;
  undefined1 uStack_37;
  undefined1 uStack_36;
  undefined1 uStack_34;
  
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x914))(*(code **)(_r_ip_funcs_p + 0x914));
  if (param_1 != 0) {
    if (*(uint *)(param_1 + 0x24) == (uint)*(ushort *)(param_1 + 0x32)) {
      (**(code **)(_r_ip_funcs_p + 0x8d0))(*(code **)(_r_ip_funcs_p + 0x8d0));
    }
    uVar7 = *(ushort *)(iVar3 + 0x18);
    if (uVar7 != 0) {
      bVar1 = *(byte *)(param_1 + 0x38);
      if ((uVar7 & 0xc0) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x3cf,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar5 = (uint)bVar1 * 0x5a + 0x16;
      uVar2 = *(ushort *)(iVar3 + iVar5);
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar3 + iVar5) = uVar7 & 0xff | uVar2 & 0xffc0;
    }
    lld_scan_sched_optimize(param_1,0xffffffff);
  }
  if ((((g_scan_forever != '\0') && (param_1 != 0)) && (*(char *)(param_1 + 0x3c) != '\x02')) &&
     (bVar1 = *(byte *)(param_1 + 0x38),
     iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc)),
     *(short *)((uint)bVar1 * 0x5a + 0x20 + iVar3) != 1)) {
    bVar1 = *(byte *)(param_1 + 0x38);
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(undefined2 *)((uint)bVar1 * 0x5a + 0x20 + iVar3) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0xffffffff;
  }
  if (param_1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00013470. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 8))("lld_scan.c",0xac6,*(code **)(_r_plf_funcs_p + 8));
    return;
  }
  bVar1 = *(byte *)(param_1 + 0x38);
  uVar6 = (uint)bVar1;
  iVar4 = uVar6 * 0x5a;
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar3 = _r_plf_funcs_p;
  uVar7 = *(ushort *)(iVar5 + iVar4) & 0x1f;
  if (*(char *)(param_1 + 0x3e) != '\x01') {
    uVar8 = 0;
    if (_lld_scan_sync_env != 0) {
      uVar8 = (uint)(*(char *)(_lld_scan_sync_env + 1) != '\0');
    }
    *(char *)(param_1 + 0x44) = (char)uVar8;
    iVar3 = (**(code **)(iVar3 + 0xbc))(0x400,*(code **)(iVar3 + 0xbc));
    uVar2 = *(ushort *)(iVar3 + iVar4 + 0x14);
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar3 + iVar4 + 0x14) = uVar2 & 0xfff7 | (ushort)(uVar8 << 3);
  }
  (**(code **)(_r_modules_funcs_p + 0x1e0))
            (uVar7,uVar6,&bStack_51,&uStack_50,*(code **)(_r_modules_funcs_p + 0x1e0));
  if (((uint)bStack_51 << 7 & 0xffffff7f) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x82,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar2 = *(ushort *)(iVar3 + iVar4);
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar3 + iVar4) = uVar2 & 0xff7f | (ushort)((uint)bStack_51 << 7);
  uVar8 = (uStack_50 & 0xff) << 6;
  if ((uVar8 & 0xffffffbf) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x8e,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar2 = *(ushort *)(iVar3 + iVar4);
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar4 + iVar3) = uVar2 & 0xffbf | (ushort)uVar8;
  (**(code **)(_r_ip_funcs_p + 0x434))(uVar6,uVar7,*(code **)(_r_ip_funcs_p + 0x434));
  uStack_50 = *(uint *)(_r_ip_funcs_p + 0x3f0);
  uStack_3b = 0;
  uStack_4c = *(undefined4 *)(param_1 + 4);
  uStack_37 = 0;
  uStack_34 = 0;
  uStack_48 = *(undefined4 *)(param_1 + 8);
  uStack_40 = (uint)*(byte *)(param_1 + 0x40);
  uStack_44 = *(undefined4 *)(param_1 + 0x10);
  uStack_3c = *(undefined1 *)(param_1 + 0x16);
  uStack_3a = rwip_priority;
  uStack_39 = 0xf;
  uStack_36 = *(char *)(param_1 + 0x3e) == '\x01';
  bStack_38 = bVar1;
  (**(code **)(_r_ip_funcs_p + 0x6c8))(&uStack_50,*(code **)(_r_ip_funcs_p + 0x6c8));
  (**(code **)(_r_ip_funcs_p + 0x714))(0,*(code **)(_r_ip_funcs_p + 0x714));
  *(undefined1 *)(param_1 + 0x3c) = 1;
  return;
}

