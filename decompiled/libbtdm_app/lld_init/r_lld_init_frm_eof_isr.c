/*
 * Last changed at upstream commit a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * https://github.com/espressif/esp32c3-bt-lib/commit/a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * Upstream date: 2021-12-28 18:10:18 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 bt lib (33175c8)
 * Source: libbtdm_app -> lld_init.o -> r_lld_init_frm_eof_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_frm_eof_isr(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  (**(code **)(_r_ip_funcs_p + 0x7b0))(param_3,*(code **)(_r_ip_funcs_p + 0x7b0));
  if (lld_init_env != 0) {
    iVar6 = *(int *)(lld_init_env + param_1 * 4);
    if (iVar6 != 0) {
      cVar1 = *(char *)(iVar6 + 0x31);
      *(undefined1 *)(iVar6 + 0x31) = 0;
      bVar2 = *(byte *)(iVar6 + 0x52);
      if (cVar1 == '\x02') {
        while( true ) {
          iVar6 = (**(code **)(_r_ip_funcs_p + 0x2a4))
                            ((uint)bVar2,*(code **)(_r_ip_funcs_p + 0x2a4));
          if (iVar6 == 0) break;
          (**(code **)(_r_ip_funcs_p + 0x2a8))(*(code **)(_r_ip_funcs_p + 0x2a8));
        }
                    /* WARNING: Could not recover jumptable at 0x00012666. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_ip_funcs_p + 0x454))();
        return;
      }
      (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar6,1,*(code **)(_r_ip_funcs_p + 0x6b8));
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar4 = (uint)bVar2 * 0x5a + 0x18;
      if ((*(ushort *)(iVar5 + iVar4) >> 10 & 1) != 0) {
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar3 = *(ushort *)(iVar5 + iVar4);
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar5 + iVar4) = uVar3 & 0xfbff;
        *(undefined1 *)(iVar6 + 0x3d) = 0;
      }
      (**(code **)(_r_ip_funcs_p + 0x474))(param_1,*(code **)(_r_ip_funcs_p + 0x474));
      (**(code **)(_r_ip_funcs_p + 0x484))(param_1,*(code **)(_r_ip_funcs_p + 0x484));
      if ((lld_init_env != 0) && (*(int *)(param_1 * 4 + lld_init_env) != 0)) {
                    /* WARNING: Could not recover jumptable at 0x00012732. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_ip_funcs_p + 0x48c))(param_1,param_2,param_3);
        return;
      }
      return;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00012766. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 0xc))(param_1,"lld_init.c",0x470);
  return;
}

