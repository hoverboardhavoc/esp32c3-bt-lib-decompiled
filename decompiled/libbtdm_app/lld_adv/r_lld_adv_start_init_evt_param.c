/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  int iVar3;
  int iVar4;
  void *__dest;
  short sVar5;
  undefined4 uVar6;
  byte bVar7;
  undefined4 uVar8;
  code *pcVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  ushort uVar15;
  int iVar16;
  
  iVar2 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x810))(1,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x810));
  if (iVar3 != 0) {
    return;
  }
  uVar6 = *(undefined4 *)(_r_ip_funcs_p + 0x1a4);
  uVar8 = *(undefined4 *)(_r_ip_funcs_p + 0x1a8);
  *(char *)(iVar2 + 0x87) = (char)param_1;
  *(undefined4 *)(iVar2 + 0x20) = uVar6;
  *(undefined4 *)(iVar2 + 0x18) = uVar8;
  bVar7 = DAT_00017055;
  uVar1 = sch_slice_params;
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  *(undefined1 *)(iVar2 + 0x16) = uVar1;
  *(ushort *)(iVar2 + 0x14) = bVar7 & 0xf | 0x6000;
  uVar6 = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(iVar2 + 8) = 0;
  *(undefined4 *)(iVar2 + 100) = uVar6;
  *(undefined2 *)(iVar2 + 0x74) = *(undefined2 *)(param_2 + 0x18);
  *(undefined1 *)(iVar2 + 0x8a) = *(undefined1 *)(param_2 + 0x26);
  memcpy((void *)(iVar2 + 0x2c),(void *)(param_2 + 6),6);
  *(undefined1 *)(iVar2 + 0x8b) = *(undefined1 *)(param_2 + 0x1e);
  *(undefined1 *)(iVar2 + 0x8c) = *(undefined1 *)(param_2 + 0x1f);
  *(undefined1 *)(iVar2 + 0x8d) = *(undefined1 *)(param_2 + 0x21);
  *(undefined1 *)(iVar2 + 0x8f) = *(undefined1 *)(param_2 + 0x23);
  bVar7 = *(byte *)(param_2 + 0x22);
  if ((bVar7 < 3) || (*(char *)(_p_lld_env + 0xda) == '\0')) {
    bVar7 = bVar7 - 1;
  }
  *(byte *)(iVar2 + 0x8e) = bVar7;
  bVar7 = *(byte *)(param_2 + 0x24);
  if ((bVar7 < 3) || (*(char *)(_p_lld_env + 0xda) == '\0')) {
    bVar7 = bVar7 - 1;
  }
  *(byte *)(iVar2 + 0x90) = bVar7;
  *(undefined *)(iVar2 + 0x93) =
       (&one_bits)[*(byte *)(param_2 + 0x1d) >> 4] + (&one_bits)[*(byte *)(param_2 + 0x1d) & 0xf];
  iVar3 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  *(ushort *)(iVar2 + 0x76) =
       *(ushort *)(iVar2 + 0x76) & 0xf000 | (ushort)((uint)(iVar3 << 0x14) >> 0x14);
  if ((*(byte *)(param_2 + 0x25) & 0xf0) != 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))(0xf000,"lld_adv.c",0xbcc,*(code **)(_r_plf_funcs_p + 0xc));
  }
  iVar3 = _r_plf_funcs_p;
  *(ushort *)(iVar2 + 0x76) =
       (ushort)*(byte *)(param_2 + 0x25) << 0xc |
       (ushort)(((uint)*(ushort *)(iVar2 + 0x76) << 0x14) >> 0x14);
  *(ushort *)(iVar2 + 0x78) = (ushort)*(byte *)(param_2 + 0x1c);
  *(undefined1 *)(iVar2 + 0x88) = 0xff;
  *(undefined2 *)(iVar2 + 0x82) = *(undefined2 *)(param_2 + 0x14);
  *(undefined2 *)(iVar2 + 0x7e) = *(undefined2 *)(param_2 + 0x10);
  *(undefined2 *)(iVar2 + 0x84) = *(undefined2 *)(param_2 + 0x16);
  *(undefined2 *)(iVar2 + 0x80) = *(undefined2 *)(param_2 + 0x12);
  if ((*(ushort *)(iVar2 + 0x74) & 0x10) == 0) {
    pcVar9 = *(code **)(iVar3 + 0xf0);
    iVar3 = (*pcVar9)(pcVar9);
    if (*(char *)(iVar3 + 0x18) == '\0') {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0xbda,*(code **)(_r_plf_funcs_p + 8));
    }
    *(bool *)(iVar2 + 0x95) = *(char *)(iVar2 + 0x8f) != '\0';
    (**(code **)(_r_ip_funcs_p + 0x1ac))
              (*(undefined1 *)(iVar2 + 0x87),*(code **)(_r_ip_funcs_p + 0x1ac));
    if (*(char *)(iVar2 + 0x95) != '\0') {
      uVar6 = *(undefined4 *)(_r_ip_funcs_p + 0x188);
      uVar8 = *(undefined4 *)(_r_ip_funcs_p + 0x18c);
      *(undefined4 *)(iVar2 + 0x50) = 0;
      *(undefined4 *)(iVar2 + 0x54) = uVar6;
      *(undefined4 *)(iVar2 + 0x4c) = uVar8;
      uVar1 = rwip_coex_cfg;
      *(undefined4 *)(iVar2 + 0x3c) = 0;
      *(undefined1 *)(iVar2 + 0x4a) = uVar1;
      *(undefined4 *)(iVar2 + 0x44) = *(undefined4 *)(iVar2 + 0x10);
      *(ushort *)(iVar2 + 0x48) = DAT_00017059 & 0xf | 0x6000;
    }
    goto _L986;
  }
  uVar11 = (uint)*(byte *)(iVar2 + 0x87) * 9 & 0xff;
  uVar12 = uVar11 + 1 & 0xff;
  uVar15 = 0;
  switch(*(ushort *)(iVar2 + 0x74) - 0x10) {
  case 0:
    uVar15 = 2;
    *(uint *)(iVar2 + 0x10) =
         (uint)*(byte *)(iVar2 + 0x93) * 0x5b2 + -300 + (uint)_sdk_cfg_priv_opts;
    break;
  default:
    pcVar9 = *(code **)(iVar3 + 8);
    (*pcVar9)(0,"lld_adv.c",0xc13,pcVar9);
    break;
  case 2:
    uVar15 = 6;
    *(uint *)(iVar2 + 0x10) =
         (uint)*(byte *)(iVar2 + 0x93) * 0x72e + -300 + (uint)_sdk_cfg_priv_opts;
    break;
  case 3:
    *(uint *)(iVar2 + 0x10) =
         (uint)*(byte *)(iVar2 + 0x93) * 0x72e + -300 + (uint)_sdk_cfg_priv_opts;
    break;
  case 5:
  case 0xd:
    uVar15 = 1;
    *(uint *)(iVar2 + 0x10) =
         (uint)*(byte *)(iVar2 + 0x93) * 0x72e + -300 + (uint)_sdk_cfg_priv_opts;
    uVar10 = *(byte *)(param_2 + 0x1f) & 1;
    goto _L993;
  }
  uVar10 = 0;
_L993:
  bVar7 = *(byte *)(param_2 + 0x1e);
  iVar16 = uVar11 * 0xe;
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar16 + 2 + iVar3) =
       (ushort)((bVar7 & 1) << 6) | (ushort)(uVar10 << 7) | uVar15 | 0x620;
  if ((*(ushort *)(iVar2 + 0x74) & 4) == 0) {
    if (*(ushort *)(param_2 + 0x14) != 0) {
      sVar5 = *(short *)(param_2 + 0x10);
      pcVar9 = *(code **)(_r_ip_funcs_p + 0x17c);
      uVar15 = *(ushort *)(param_2 + 0x14) & 0xff;
      goto _L1029;
    }
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(undefined2 *)(iVar16 + 4 + iVar3) = 0;
    iVar3 = (**(code **)(_r_modules_funcs_p + 0x1a0))(2,*(code **)(_r_modules_funcs_p + 0x1a0));
    if (iVar3 != 0) {
      if (2 < _g_bt_plf_log_level) {
        ets_printf("TX PTI [LDC] [EN%d] [%d] \n",*(undefined1 *)(iVar3 + 4),
                   *(undefined1 *)(iVar3 + 5));
      }
      bVar7 = *(byte *)(iVar3 + 5);
      if ((bVar7 & 0xf0) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar13 = iVar16 + 10;
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar15 = *(ushort *)(iVar4 + iVar13);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      pcVar9 = *(code **)(_r_plf_funcs_p + 0xbc);
      *(ushort *)(iVar4 + iVar13) = uVar15 & 0xf0ff | (ushort)bVar7 << 8;
      bVar7 = *(byte *)(iVar3 + 4);
      iVar3 = (*pcVar9)(0x1400,pcVar9);
      uVar15 = *(ushort *)(iVar3 + iVar13);
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar3 + iVar13) = uVar15 & 0xefff | (ushort)bVar7 << 0xc;
    }
  }
  else {
    sVar5 = (ushort)*(byte *)(iVar2 + 0x87) * 0x4b + 0x2000;
    __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(sVar5,*(code **)(_r_plf_funcs_p + 0xbc));
    memcpy(__dest,(void *)(param_2 + 6),6);
    pcVar9 = *(code **)(_r_ip_funcs_p + 0x17c);
    uVar15 = 6;
_L1029:
    (*pcVar9)(param_1,uVar15,sVar5,0,0,pcVar9);
  }
  iVar4 = uVar12 * 0xe;
  bVar7 = *(byte *)(param_2 + 0x1e);
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar13 = iVar4 + 2;
  *(ushort *)(iVar3 + iVar13) = (ushort)((bVar7 & 1) << 6) | 4;
  if ((*(ushort *)(iVar2 + 0x74) & 4) == 0) {
    if (*(ushort *)(param_2 + 0x16) == 0) {
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar15 = *(ushort *)(iVar3 + iVar13);
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      pcVar9 = *(code **)(_r_plf_funcs_p + 0xbc);
      *(ushort *)(iVar3 + iVar13) = uVar15 & 0xff | 0x600;
      iVar3 = (*pcVar9)(0x1400,pcVar9);
      *(undefined2 *)(iVar4 + 4 + iVar3) = 0;
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar15 = *(ushort *)(iVar3 + iVar4);
      iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(*(code **)(_r_plf_funcs_p + 0xbc));
      iVar3 = _r_modules_funcs_p;
      *(ushort *)(iVar13 + iVar4) = (short)uVar11 * 0xe + 0x1400U | uVar15 & 0x8000;
      iVar3 = (**(code **)(iVar3 + 0x1a0))(2,*(code **)(iVar3 + 0x1a0));
      if (iVar3 != 0) {
        if (2 < _g_bt_plf_log_level) {
          ets_printf("TX PTI [LDC ADV] [EN%d] [%d] \n",*(undefined1 *)(iVar3 + 4),
                     *(undefined1 *)(iVar3 + 5));
        }
        bVar7 = *(byte *)(iVar3 + 5);
        if ((bVar7 & 0xf0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
        }
        iVar14 = iVar4 + 10;
        iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar15 = *(ushort *)(iVar13 + iVar14);
        iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        pcVar9 = *(code **)(_r_plf_funcs_p + 0xbc);
        *(ushort *)(iVar13 + iVar14) = uVar15 & 0xf0ff | (ushort)bVar7 << 8;
        bVar7 = *(byte *)(iVar3 + 4);
        iVar3 = (*pcVar9)(0x1400,pcVar9);
        uVar15 = *(ushort *)(iVar3 + iVar14);
        iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar3 + iVar14) = uVar15 & 0xefff | (ushort)bVar7 << 0xc;
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
    uVar15 = *(ushort *)(iVar2 + iVar16);
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar2 = _r_plf_funcs_p;
    *(ushort *)(iVar3 + iVar16) = (short)uVar12 * 0xe + 0x1400U | uVar15 & 0x8000;
    iVar2 = (**(code **)(iVar2 + 0xbc))(0x1400,*(code **)(iVar2 + 0xbc));
    uVar15 = *(ushort *)(iVar2 + iVar4);
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar4 + iVar2) = (ushort)(((uint)uVar15 << 0x11) >> 0x11);
  }
  else {
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400);
    uVar15 = *(ushort *)(iVar2 + iVar16);
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar2 + iVar16) = uVar15 & 0x8000;
  }
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar15 = *(ushort *)(iVar2 + iVar16);
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar16 + iVar2) = (ushort)(((uint)uVar15 << 0x11) >> 0x11);
_L986:
                    /* WARNING: Could not recover jumptable at 0x00015072. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x810))(0,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x810));
  return;
}

