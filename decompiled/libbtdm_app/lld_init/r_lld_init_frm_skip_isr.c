/*
 * Last changed at upstream commit a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * https://github.com/espressif/esp32c3-bt-lib/commit/a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * Upstream date: 2021-12-28 18:10:18 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 bt lib (33175c8)
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
  
  if (lld_init_env != 0) {
    iVar4 = *(int *)(lld_init_env + param_1 * 4);
    if (iVar4 != 0) {
      iVar5 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
      cVar1 = *(char *)(iVar4 + 0x31);
      *(undefined1 *)(iVar4 + 0x31) = 0;
      if (cVar1 == '\x02') {
                    /* WARNING: Could not recover jumptable at 0x000127e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_ip_funcs_p + 0x454))();
        return;
      }
      (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar4,1,*(code **)(_r_ip_funcs_p + 0x6b8));
      bVar3 = rwip_priority;
      if ((uint)*(ushort *)(iVar4 + 0x2c) << 1 <= (iVar5 - *(int *)(iVar4 + 0x28) & 0xfffffffU)) {
        if (0xff < (uint)*(byte *)(iVar4 + 0x16) + (uint)rwip_priority) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x49a,*(code **)(_r_plf_funcs_p + 8));
        }
        *(int *)(iVar4 + 0x28) = iVar5;
        *(byte *)(iVar4 + 0x16) = bVar3 + *(char *)(iVar4 + 0x16);
      }
      iVar2 = _r_ip_funcs_p;
      if (*(char *)(iVar4 + 0x3d) == '\x01') {
        *(undefined1 *)(iVar4 + 0x3d) = 0;
                    /* WARNING: Could not recover jumptable at 0x000128a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(iVar2 + 0x48c))(param_1,iVar5,1);
        return;
      }
      iVar4 = (**(code **)(_r_ip_funcs_p + 0x6b0))(iVar4,*(code **)(_r_ip_funcs_p + 0x6b0));
      if (iVar4 == 0) {
        return;
      }
      uVar6 = 0x4a6;
      UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
      goto _L350;
    }
  }
  uVar6 = 0x4b4;
  UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
_L350:
                    /* WARNING: Could not recover jumptable at 0x00012886. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(0,"lld_init.c",uVar6);
  return;
}

