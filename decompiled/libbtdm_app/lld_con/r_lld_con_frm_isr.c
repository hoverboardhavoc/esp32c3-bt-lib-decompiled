/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_frm_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_frm_isr(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char cVar6;
  
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar2 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0001311e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0xbec);
    return;
  }
  (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar2,1,*(code **)(_r_ip_funcs_p + 0x6b8));
  if (*(char *)(iVar2 + 0x8f) == '\x02') {
    uVar5 = 0x3d;
    if ((*(ushort *)(iVar2 + 0x84) & 0x80) == 0) {
      uVar5 = 0x16;
    }
                    /* WARNING: Could not recover jumptable at 0x00012fa0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 800))(param_1,1,uVar5);
    return;
  }
  uVar5 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  if (sdk_cfg_priv_opts != '\0') {
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(iVar3 + param_1 * 0x5a + 0x56);
    iVar3 = param_1 * 0x5a + 0x18;
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    if ((((&g_event_empty)[param_1] == '\x01') && (uVar1 >> 8 == 0)) &&
       ((*(ushort *)(iVar4 + iVar3) >> 0xe & 1) == 0)) {
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar1 = *(ushort *)(iVar4 + iVar3);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar3 + iVar4) = uVar1 & 0xbfff | 0x4000;
    }
    else {
      (&g_event_empty)[param_1] = (byte)(*(ushort *)(iVar4 + iVar3) >> 0xe) & 1;
    }
  }
  uVar1 = *(ushort *)(iVar2 + 0x84);
  iVar3 = 5;
  if ((((uVar1 & 6) == 2) && ((uVar1 & 8) == 0)) && (iVar3 = 4, *(char *)(iVar2 + 0x46) == '\x01'))
  {
    iVar3 = 5;
  }
  *(uint *)(iVar2 + 0x48) = *(int *)(iVar2 + 0x48) + *(int *)(iVar2 + 100) & 0xfffffff;
  *(short *)(iVar2 + 0x7e) = *(short *)(iVar2 + 0x7e) + 1;
  if (param_2 == 0) {
    cVar6 = (&rwip_priority)[iVar3 * 2];
  }
  else {
    cVar6 = *(char *)(iVar3 * 2 + 0x16011) + *(char *)(iVar2 + 0x16);
  }
  *(char *)(iVar2 + 0x16) = cVar6;
                    /* WARNING: Could not recover jumptable at 0x000130de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x3a8))(param_1,uVar5,(int)(uint)uVar1 >> 8 & 1);
  return;
}

