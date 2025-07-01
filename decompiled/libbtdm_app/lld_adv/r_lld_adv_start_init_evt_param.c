/*
 * Last changed at upstream commit 0c68809d62e432427de97b5294f6619307f62f40
 * https://github.com/espressif/esp32c3-bt-lib/commit/0c68809d62e432427de97b5294f6619307f62f40
 * Upstream date: 2025-07-01 15:07:54 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2edb0b0)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_start_init_evt_param
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_start_init_evt_param(int param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  void *__dest;
  short sVar6;
  undefined4 uVar7;
  uint uVar8;
  byte bVar9;
  undefined4 uVar10;
  code *pcVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  
  iVar2 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x810))(1,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x810));
  if (iVar4 != 0) {
    return;
  }
  uVar7 = *(undefined4 *)(_r_ip_funcs_p + 0x1a4);
  uVar10 = *(undefined4 *)(_r_ip_funcs_p + 0x1a8);
  *(char *)(iVar2 + 0x87) = (char)param_1;
  *(undefined4 *)(iVar2 + 0x20) = uVar7;
  *(undefined4 *)(iVar2 + 0x18) = uVar10;
  bVar9 = DAT_00017055;
  uVar1 = sch_slice_params;
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  *(undefined1 *)(iVar2 + 0x16) = uVar1;
  *(ushort *)(iVar2 + 0x14) = bVar9 & 0xf | 0x6000;
  uVar7 = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(iVar2 + 8) = 0;
  *(undefined4 *)(iVar2 + 100) = uVar7;
  *(undefined2 *)(iVar2 + 0x74) = *(undefined2 *)(param_2 + 0x18);
  *(undefined1 *)(iVar2 + 0x8a) = *(undefined1 *)(param_2 + 0x26);
  memcpy((void *)(iVar2 + 0x2c),(void *)(param_2 + 6),6);
  *(undefined1 *)(iVar2 + 0x8b) = *(undefined1 *)(param_2 + 0x1e);
  *(undefined1 *)(iVar2 + 0x8c) = *(undefined1 *)(param_2 + 0x1f);
  *(undefined1 *)(iVar2 + 0x8d) = *(undefined1 *)(param_2 + 0x21);
  *(undefined1 *)(iVar2 + 0x8f) = *(undefined1 *)(param_2 + 0x23);
  bVar9 = *(byte *)(param_2 + 0x22);
  if ((bVar9 < 3) || (*(char *)(_p_lld_env + 0xda) == '\0')) {
    bVar9 = bVar9 - 1;
  }
  *(byte *)(iVar2 + 0x8e) = bVar9;
  bVar9 = *(byte *)(param_2 + 0x24);
  if ((bVar9 < 3) || (*(char *)(_p_lld_env + 0xda) == '\0')) {
    bVar9 = bVar9 - 1;
  }
  *(byte *)(iVar2 + 0x90) = bVar9;
  *(undefined *)(iVar2 + 0x93) =
       (&one_bits)[*(byte *)(param_2 + 0x1d) >> 4] + (&one_bits)[*(byte *)(param_2 + 0x1d) & 0xf];
  uVar3 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  *(ushort *)(iVar2 + 0x76) = *(ushort *)(iVar2 + 0x76) & 0xf000 | uVar3 & 0xfff;
  if ((*(byte *)(param_2 + 0x25) & 0xf0) != 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))(0xf000,"lld_adv.c",0xbd1,*(code **)(_r_plf_funcs_p + 0xc));
  }
  iVar4 = _r_plf_funcs_p;
  *(ushort *)(iVar2 + 0x76) =
       *(ushort *)(iVar2 + 0x76) & 0xfff | (ushort)*(byte *)(param_2 + 0x25) << 0xc;
  *(ushort *)(iVar2 + 0x78) = (ushort)*(byte *)(param_2 + 0x1c);
  *(undefined1 *)(iVar2 + 0x88) = 0xff;
  *(undefined2 *)(iVar2 + 0x82) = *(undefined2 *)(param_2 + 0x14);
  *(undefined2 *)(iVar2 + 0x7e) = *(undefined2 *)(param_2 + 0x10);
  *(undefined2 *)(iVar2 + 0x84) = *(undefined2 *)(param_2 + 0x16);
  *(undefined2 *)(iVar2 + 0x80) = *(undefined2 *)(param_2 + 0x12);
  if ((*(ushort *)(iVar2 + 0x74) & 0x10) == 0) {
    pcVar11 = *(code **)(iVar4 + 0xf0);
    iVar4 = (*pcVar11)(pcVar11);
    if (*(char *)(iVar4 + 0x18) == '\0') {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0xbdf,*(code **)(_r_plf_funcs_p + 8));
    }
    *(bool *)(iVar2 + 0x95) = *(char *)(iVar2 + 0x8f) != '\0';
    (**(code **)(_r_ip_funcs_p + 0x1ac))
              (*(undefined1 *)(iVar2 + 0x87),*(code **)(_r_ip_funcs_p + 0x1ac));
    if (*(char *)(iVar2 + 0x95) != '\0') {
      uVar7 = *(undefined4 *)(_r_ip_funcs_p + 0x188);
      uVar10 = *(undefined4 *)(_r_ip_funcs_p + 0x18c);
      *(undefined4 *)(iVar2 + 0x50) = 0;
      *(undefined4 *)(iVar2 + 0x54) = uVar7;
      *(undefined4 *)(iVar2 + 0x4c) = uVar10;
      uVar1 = rwip_coex_cfg;
      *(undefined4 *)(iVar2 + 0x3c) = 0;
      *(undefined1 *)(iVar2 + 0x4a) = uVar1;
      *(undefined4 *)(iVar2 + 0x44) = *(undefined4 *)(iVar2 + 0x10);
      *(ushort *)(iVar2 + 0x48) = DAT_00017059 & 0xf | 0x6000;
    }
    goto _L1054;
  }
  uVar13 = (uint)*(byte *)(iVar2 + 0x87) * 9 & 0xff;
  uVar8 = uVar13 + 1 & 0xff;
  uVar3 = 0;
  switch(*(ushort *)(iVar2 + 0x74) - 0x10) {
  case 0:
    uVar3 = 2;
    *(uint *)(iVar2 + 0x10) =
         (uint)*(byte *)(iVar2 + 0x93) * 0x5b2 + -300 + (uint)_sdk_cfg_priv_opts;
    break;
  default:
    pcVar11 = *(code **)(iVar4 + 8);
    (*pcVar11)(0,"lld_adv.c",0xc18,pcVar11);
    break;
  case 2:
    uVar3 = 6;
    *(uint *)(iVar2 + 0x10) =
         (uint)*(byte *)(iVar2 + 0x93) * 0x72e + -300 + (uint)_sdk_cfg_priv_opts;
    break;
  case 3:
    *(uint *)(iVar2 + 0x10) =
         (uint)*(byte *)(iVar2 + 0x93) * 0x72e + -300 + (uint)_sdk_cfg_priv_opts;
    break;
  case 5:
  case 0xd:
    uVar3 = 1;
    *(uint *)(iVar2 + 0x10) =
         (uint)*(byte *)(iVar2 + 0x93) * 0x72e + -300 + (uint)_sdk_cfg_priv_opts;
    uVar12 = *(byte *)(param_2 + 0x1f) & 1;
    goto _L1061;
  }
  uVar12 = 0;
_L1061:
  bVar9 = *(byte *)(param_2 + 0x1e);
  iVar16 = uVar13 * 0xe;
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar16 + 2 + iVar4) =
       (ushort)((bVar9 & 1) << 6) | (ushort)(uVar12 << 7) | uVar3 | 0x620;
  if ((*(ushort *)(iVar2 + 0x74) & 4) == 0) {
    if (*(ushort *)(param_2 + 0x14) != 0) {
      sVar6 = *(short *)(param_2 + 0x10);
      pcVar11 = *(code **)(_r_ip_funcs_p + 0x17c);
      uVar3 = *(ushort *)(param_2 + 0x14) & 0xff;
      goto _L1097;
    }
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(undefined2 *)(iVar16 + 4 + iVar4) = 0;
    iVar4 = (**(code **)(_r_modules_funcs_p + 0x1a0))(2,*(code **)(_r_modules_funcs_p + 0x1a0));
    if (iVar4 != 0) {
      if (2 < _g_bt_plf_log_level) {
        ets_printf("TX PTI [LDC] [EN%d] [%d] \n",*(undefined1 *)(iVar4 + 4),
                   *(undefined1 *)(iVar4 + 5));
      }
      uVar12 = (uint)*(byte *)(iVar4 + 5) << 8;
      if ((uVar12 & 0xf000) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar14 = iVar16 + 10;
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar3 = *(ushort *)(iVar5 + iVar14);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      pcVar11 = *(code **)(_r_plf_funcs_p + 0xbc);
      *(ushort *)(iVar5 + iVar14) = uVar3 & 0xf0ff | (ushort)uVar12;
      bVar9 = *(byte *)(iVar4 + 4);
      iVar4 = (*pcVar11)(0x1400,pcVar11);
      uVar3 = *(ushort *)(iVar4 + iVar14);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + iVar14) = uVar3 & 0xefff | (ushort)bVar9 << 0xc;
    }
  }
  else {
    sVar6 = (ushort)*(byte *)(iVar2 + 0x87) * 0x4b + 0x2000;
    __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(sVar6,*(code **)(_r_plf_funcs_p + 0xbc));
    memcpy(__dest,(void *)(param_2 + 6),6);
    pcVar11 = *(code **)(_r_ip_funcs_p + 0x17c);
    uVar3 = 6;
_L1097:
    (*pcVar11)(param_1,uVar3,sVar6,0,0,pcVar11);
  }
  bVar9 = *(byte *)(param_2 + 0x1e);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar5 = uVar8 * 0xe;
  iVar14 = iVar5 + 2;
  *(ushort *)(iVar4 + iVar14) = (ushort)((bVar9 & 1) << 6) | 4;
  if ((*(ushort *)(iVar2 + 0x74) & 4) == 0) {
    if (*(ushort *)(param_2 + 0x16) == 0) {
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar3 = *(ushort *)(iVar4 + iVar14);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      pcVar11 = *(code **)(_r_plf_funcs_p + 0xbc);
      *(ushort *)(iVar4 + iVar14) = uVar3 & 0xff | 0x600;
      iVar4 = (*pcVar11)(0x1400,pcVar11);
      *(undefined2 *)(iVar5 + 4 + iVar4) = 0;
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar3 = *(ushort *)(iVar4 + iVar5);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      pcVar11 = *(code **)(_r_modules_funcs_p + 0x1a0);
      *(ushort *)(iVar4 + iVar5) = (short)uVar13 * 0xe + 0x1400U | uVar3 & 0x8000;
      iVar4 = (*pcVar11)(2,pcVar11);
      if (iVar4 != 0) {
        if (2 < _g_bt_plf_log_level) {
          ets_printf("TX PTI [LDC ADV] [EN%d] [%d] \n",*(undefined1 *)(iVar4 + 4),
                     *(undefined1 *)(iVar4 + 5));
        }
        uVar13 = (uint)*(byte *)(iVar4 + 5) << 8;
        if ((uVar13 & 0xf000) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
        }
        iVar15 = iVar5 + 10;
        iVar14 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar3 = *(ushort *)(iVar14 + iVar15);
        iVar14 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        pcVar11 = *(code **)(_r_plf_funcs_p + 0xbc);
        *(ushort *)(iVar14 + iVar15) = uVar3 & 0xf0ff | (ushort)uVar13;
        bVar9 = *(byte *)(iVar4 + 4);
        iVar4 = (*pcVar11)(0x1400,pcVar11);
        uVar3 = *(ushort *)(iVar4 + iVar15);
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar4 + iVar15) = uVar3 & 0xefff | (ushort)bVar9 << 0xc;
      }
    }
    else {
      (**(code **)(_r_ip_funcs_p + 0x1d8))
                (param_1,*(ushort *)(param_2 + 0x16) & 0xff,*(undefined2 *)(param_2 + 0x12),0,0,
                 *(code **)(_r_ip_funcs_p + 0x1d8));
    }
  }
  if ((*(ushort *)(iVar2 + 0x74) & 6) == 2) {
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400);
    uVar3 = *(ushort *)(iVar2 + iVar16);
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    pcVar11 = *(code **)(_r_plf_funcs_p + 0xbc);
    *(ushort *)(iVar2 + iVar16) = (short)uVar8 * 0xe + 0x1400U | uVar3 & 0x8000;
    iVar2 = (*pcVar11)(0x1400,pcVar11);
    uVar3 = *(ushort *)(iVar2 + iVar5);
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar5 + iVar2) = (ushort)(((uint)uVar3 << 0x11) >> 0x11);
  }
  else {
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400);
    uVar3 = *(ushort *)(iVar2 + iVar16);
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar2 + iVar16) = uVar3 & 0x8000;
  }
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar3 = *(ushort *)(iVar2 + iVar16);
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar16 + iVar2) = (ushort)(((uint)uVar3 << 0x11) >> 0x11);
_L1054:
                    /* WARNING: Could not recover jumptable at 0x0001519c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x810))(0,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x810));
  return;
}

