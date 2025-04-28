/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  undefined4 uVar4;
  char cVar5;
  int iVar6;
  
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar2 == 0) {
                    /* WARNING: Could not recover jumptable at 0x000130ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0xc11,*(code **)(_r_plf_funcs_p + 8));
    return;
  }
  (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar2,1,*(code **)(_r_ip_funcs_p + 0x6b8));
  if (*(char *)(iVar2 + 0x8f) == '\x02') {
    uVar4 = 0x3d;
    if ((*(ushort *)(iVar2 + 0x84) & 0x80) == 0) {
      uVar4 = 0x16;
    }
                    /* WARNING: Could not recover jumptable at 0x00012f56. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 800))(param_1,1,uVar4,*(code **)(_r_ip_funcs_p + 800));
    return;
  }
  uVar4 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  if (sdk_cfg_priv_opts != '\0') {
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(param_1 * 0x5a + 0x56 + iVar3);
    iVar6 = param_1 * 0x5a + 0x18;
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    if ((((&g_event_empty)[param_1] == '\x01') && (uVar1 >> 8 == 0)) &&
       ((*(ushort *)(iVar3 + iVar6) >> 0xe & 1) == 0)) {
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar1 = *(ushort *)(iVar3 + iVar6);
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar3 + iVar6) = uVar1 & 0xbfff | 0x4000;
    }
    else {
      (&g_event_empty)[param_1] = (byte)(*(ushort *)(iVar3 + iVar6) >> 0xe) & 1;
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
    cVar5 = (&rwip_priority)[iVar3 * 2];
  }
  else {
    cVar5 = *(char *)(iVar3 * 2 + 0x16011) + *(char *)(iVar2 + 0x16);
  }
  *(char *)(iVar2 + 0x16) = cVar5;
                    /* WARNING: Could not recover jumptable at 0x00013090. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x3a8))
            (param_1,uVar4,(int)(uint)uVar1 >> 8 & 1,*(code **)(_r_ip_funcs_p + 0x3a8));
  return;
}

